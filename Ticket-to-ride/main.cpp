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
        int N_jugadores = 4;
        vector<Jugador> Jugadores;
        Mapa miMapa;
        Graphics Graphics;
        Baraja Baraja;
        
    public:
        Juego(){
            for (int i = 0; i < N_jugadores; i++){
                Jugadores.emplace_back(i + 1);
            }
            Graphics.limpiar_pantalla();
            Jugar();
            
        }

        void Jugar(){
            ZonaCarta ZonaCartas(&Baraja);
            while(true){
                Graphics.limpiar_pantalla();
                for (auto it = Jugadores.begin(); it != Jugadores.end(); ) {
                    stringstream jugador_text; 
                    jugador_text << "::: Turno del jugador " << it->getID() << " :::";
                    Graphics.print_completo(jugador_text.str(), 88, 2);

                    if (it->getVagones() < 1) {
                        it = Jugadores.erase(it);
                    }
                    miMapa.show();

                    //Imprimir rutas disponibles
                    vector<rutaComponente> rutasDispo = miMapa.getRutasDisponibles();


                    vector<string> opciones_jugador = {"Robar 2 cartas", "Hacer una ruta"};
                    string opcion = Graphics.select_opciones("-- ¿Que accion desea realizar?",opciones_jugador, 6, 88);
                    
                    if (opcion == opciones_jugador[0]){
                        vector<char> coloresCrudos = {'v', 'a', 'r', 'm', 'c', 'n'};
                        vector<string> color = {"GREEN", "YELLOW", "RED", "MAGENTA", "BLUE", "ROSE"};

                        vector<char> cartas = ZonaCartas.escogerCartas(&Baraja);
                        for (int i = 0; i < cartas.size(); i++){
                            int index = 0;
                            for (int j = 0; j < coloresCrudos.size(); ++j) {
                                if (coloresCrudos[j] == cartas[i]) {
                                    index = j;
                                    break;
                                }
                            }
                            Graphics.print_cartas("□", 88, 9 + (i * 4), color[index]);
                        }
                        stringstream ss;

                        vector<string> opciones_jugador = {"1", "2", "3", "4"};
                        string opcion1 = Graphics.select_opciones("-- primera carta",opciones_jugador, 12, 100);
                        auto it = remove(opciones_jugador.begin(), opciones_jugador.end(), opcion1);
                        opciones_jugador.erase(it, opciones_jugador.end());
                        string opcion2 = Graphics.select_opciones("-- segunda opcion carta",opciones_jugador, 20, 100);
                    }
                }
            }
        }

        void mostrarRutas(vector<rutaComponente> rutasDispo){
            for (int i = 0; i < rutasDispo.size(); i++){
                        rutaComponente ruta = rutasDispo[i];
                        stringstream ruta_txt;
                        string rutaLong = "";
                        for (int j = 0; j < ruta.posiciones.size(); j++){
                            rutaLong += "□";
                        }
                        ruta_txt << "/// [" << ruta.id << "] " << rutaLong << " De " << ruta.ciudades[0] << " a " << ruta.ciudades[1]; 
                        Graphics.print_completo(ruta_txt.str(), 88, 7 + i, ruta.color);
                    }
        }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IONBF, 0);
	Juego Juego;
    return 0;
}

