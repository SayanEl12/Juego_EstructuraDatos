#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include "Utils/Tablero/mapa.cpp"
#include "Utils/Jugador/Jugador.cpp"
#include "Utils/Barajas/baraja.cpp"

using namespace std;

class Juego{
    private:
        int N_jugadores = 2;
        map<int, int> leyendaPuntos = {{2,1},{3,2},{4,4},{5,6},{6,9}};
        vector<Jugador> Jugadores;
        Mapa miMapa;
        Graphics Graphics;
        Baraja Baraja;
        
    public:
        Juego(){
            map<string, string> colores = Graphics.getColores();
            map<string, string>::iterator color = colores.begin();
            for (int i = 0; i < N_jugadores; i++){
                Jugadores.emplace_back(i + 1, color->first);
                for (int j = 0; j < 4; j++){
                    Jugadores[i].addCarta(Baraja.robarCarta());
                }
                ++color;
            }
            Graphics.limpiar_pantalla();
            Jugar();
        }

        void Jugar(){
            ZonaCarta ZonaCartas(&Baraja);
            while(true){
                Graphics.limpiar_pantalla();
                for (auto jugador = Jugadores.begin(); jugador != Jugadores.end(); jugador++) {
                    // Revisa si el jugador tiene vagones suficientes para continuar
                    Graphics.limpiar_pantalla();
                    

                    if (N_jugadores < 2){
                        sacarGanador(Jugadores);
                    }

                    stringstream jugador_text; 
                    jugador_text << "::: Turno del jugador " << jugador->getID() << " :::";
                    Graphics.print_completo(jugador_text.str(), 88, 2, jugador->getColor());

                    stringstream vagones_text; 
                    vagones_text << "N vagones:" << jugador->getVagones();
                    Graphics.print_completo(vagones_text.str(), 116, 2);
                    
                    miMapa.show();

                    // Revisar si tiene vagones suficientes
                    if (jugador->getVagones() < 5) {
                        Graphics.print_completo("YA NO TIENES VAGONES !! :C", 88, 15);
                        N_jugadores -= 1;
                        Graphics.esperar();
                        continue;
                    }
                    mostrarCartasJug(89, 26, jugador);

                    map<string, int> opciones_jugador = {{"Robar 2 cartas", 0}, {"Hacer una ruta", 1}};
                    int opcion = Graphics.select_opciones("-- ¿Que accion desea realizar?",opciones_jugador, 6, 88);
                    
                    // Robar cartas
                    if (opcion == 0){
                        // mostrando cartas de la zona de cartas
                        vector<string> cartas = ZonaCartas.mostrarCartas();
                        for (int i = 0; i < cartas.size(); i++){
                            Graphics.print_cartas(to_string(i + 1), 88, 9 + (i * 4), cartas[i]);
                        }

                        // Guardar las selecciones en opcion1 y opcion2
                        map<string, int> opciones_jugador = {{"1",1},{"2",2},{"3",3},{"4",4}};
                        int opcion1 = Graphics.select_opciones("-- primera carta",opciones_jugador, 12, 100);
                        ZonaCartas.robarCarta(opcion1 - 1);
                        jugador->addCarta(cartas[opcion1 - 1]);
                        mostrarCartasJug(89, 26, jugador);

                        for (auto it = opciones_jugador.begin(); it != opciones_jugador.end(); ) {
                            if (it->second == opcion1) {
                                it = opciones_jugador.erase(it); // Elimina el elemento y actualiza el iterador
                            } else {
                                ++it;
                            }
                        }
                        int opcion2 = Graphics.select_opciones("-- segunda opcion carta",opciones_jugador, 20, 100);
                        ZonaCartas.robarCarta(opcion2 - 1);
                        jugador->addCarta(cartas[opcion2 - 1]);
                        mostrarCartasJug(89, 26, jugador);
                        Graphics.esperar();
                    }
                    // Hacer ruta
                    else {
                        //Imprimir rutas disponibles
                        vector<rutaComponente> rutasDispo = miMapa.getRutasDisponibles();
                        map<string, int> cartasJugador = jugador->getCartas();
                        vector<rutaComponente> rutasValidas;

                        if (cartasJugador.size() > 1){
                            for (auto ruta = rutasDispo.begin(); ruta != rutasDispo.end(); ruta++){
                                for (auto colorJug = cartasJugador.begin(); colorJug != cartasJugador.end(); colorJug++){
                                    if (ruta->color == colorJug->first){
                                        if (ruta->posiciones.size() <=colorJug->second){
                                            rutasValidas.push_back(*ruta);
                                        }
                                    }
                                }
                            }
                        }
                        
                        if (rutasValidas.size() > 0){
                            map<string, int> textoRutas = formatearRutas(rutasValidas);
                            int idRuta = Graphics.select_opciones("Escoje la ruta que deseas:", textoRutas, 10, 88);
                            auto rutaSelec = find_if(rutasValidas.begin(), rutasValidas.end(), [&idRuta](const rutaComponente& r) {
                                return r.id == idRuta;
                            });
                            jugador->usarCartas(rutaSelec->color, rutaSelec->posiciones.size());
                            Baraja.addDescarte(rutaSelec->color, rutaSelec->posiciones.size());
                            miMapa.setRuta(idRuta, jugador->getColor());
                            jugador->agregarPuntos(leyendaPuntos[rutaSelec->posiciones.size()]);
                        }else {
                            Graphics.print_completo("No hay rutas disponibles", 88, 10);
                            Graphics.esperar();
                        }
                    }
                }
            }
        }

        map<string, int> formatearRutas(vector<rutaComponente> rutasDispo){
            map<string, int> rutasTuned;

            for (int i = 0; i < rutasDispo.size(); i++){
                map<string, string>colores = Graphics.getColores();
                string colorCode = colores[rutasDispo[i].color];
                rutaComponente ruta = rutasDispo[i];
                stringstream ruta_txt;
                string rutaLong = "";
                for (int j = 0; j < ruta.posiciones.size(); j++){
                    rutaLong += "□ ";
                }
                ruta_txt << colorCode <<"/// [" << ruta.id << "] " << rutaLong << " De " << ruta.ciudades[0] << " a " << ruta.ciudades[1]; 
                //Graphics.print_completo(ruta_txt.str(), 88, 10 + i, ruta.color);
                rutasTuned[ruta_txt.str()] = ruta.id;
            }

            return rutasTuned;
        }

        void mostrarCartasJug(int x, int y, vector<Jugador>::iterator jugador){
            // Mostrar las en el jugador
            map<string, int> jugCartas = jugador->getCartas();
            map<string, int>::iterator carta = jugCartas.begin();
            int i = 0;
            while (carta != jugCartas.end()) {
                Graphics.print_cartas(to_string(carta->second),x + (i * 5), y, carta->first);
                i ++;
                ++carta;
            }
        }

        void sacarGanador(vector<Jugador> jugadores){
            int puntosGanadores = 0;
            int idGanador;
            int y = 5;

            for (int i = 0; i < jugadores.size(); i++){
                stringstream jugador_text; 
                jugador_text << "Jugador" << jugadores[i].getID() << ": " << jugadores[i].getPuntos() << " Puntos";
                Graphics.print_completo(jugador_text.str(), 50, 5 + i);

                if (jugadores[i].getPuntos() > puntosGanadores){
                    idGanador = jugadores[i].getID();
                }
                y++;
            }
            stringstream ganador_text;
            ganador_text << "GANADOR Jugador" << idGanador;
            Graphics.print_completo(ganador_text.str(), 50, y + 1);
            Graphics.esperar();

        }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IONBF, 0);
	Juego Juego;
    return 0;
}

