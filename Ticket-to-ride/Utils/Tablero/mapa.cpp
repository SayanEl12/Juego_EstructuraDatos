#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include "../Graficador/graphics.cpp"
#include "celda.cpp"
#include "rutas.cpp"
#include "ciudades.cpp"


/*╔  ═  ╤  ╗  ╚  ═  ╧   ╝  ╟  ╢  ║
─  ┼  ─  │
█ □
╔═╤═╗
║X│O║
╟─┼─╢
║O│X║
╚═╧═╝*/

using namespace std;

class Mapa{
    private:
        const int FILAS = 14;
        const int COLUMNAS = 19;
        const int Xinicial = 5;
        const int Yinicial = 2;
        Celda*** mapa = new Celda**[FILAS];
        Graphics Graphics;
    public:
        Mapa(){
            // inicizalizar las filas
            for (int i = 0; i < FILAS; i++){
                mapa[i] = new Celda*[COLUMNAS];
                // inicizalizando las columnas
                for (int j = 0; j < COLUMNAS; j++) {
                    mapa[i][j] = new Celda(" "); // Crear una nueva instancia de Celda
                }
            }

            // Registrando las rutas
            for (const auto& ruta : rutasDefinidas){
                for (const auto& pos : ruta.posiciones){
                    mapa[pos.y - 1][pos.x - 1]->setEstado("□", ruta.color, 1);
                }
            }

            // Registrando ciudades
            for (const auto& ciudad : ciudades){
                for (const auto& pos : ciudad.posiciones){
                    mapa[pos.y - 1][pos.x - 1]->setEstado(ciudad.nombre, "WHITE", 1);
                }
            }
        }

        // Regresar un string centrado
        string centrarPrint(int val, int size){
            string str = to_string(val+1);
            string centeredStr = string((size - str.length()) / 2, ' ') + str + string((size - str.length()) / 2, ' ');
            stringstream ss;
            ss << setw(size) << centeredStr;
            string fixedStr = ss.str();
            return fixedStr;
        }

        // Iprimir el mapa
        void show() {
            
            for (int i = 0; i <  FILAS; i++){
                // Imprimir indice de la fila
                Graphics.print_completo(centrarPrint(i, 2), Xinicial - 3, Yinicial + (i * 2) + 1);

                for (int j = 0; j < COLUMNAS; j++){
                    // Imprimir indice de la columna
                    Graphics.print_completo(centrarPrint(j, 4), Xinicial + (j*4), Yinicial-1);
                    string color = mapa[i][j]->getEstado()->color;
                    // Primera fila
                    if (i == 0){
                        string valCelda = mapa[i][j]->getEstado()->contenido;
                        if (j == 0) {
                            string celda = "║ " + valCelda + " ";
                            Graphics.print_completo("╔═══", Xinicial, Yinicial, color);
                            Graphics.print_completo(celda, Xinicial, Yinicial + 1, color);
                            Graphics.print_completo("╟───", Xinicial, Yinicial + 2, color);
                        }
                        else if (j < COLUMNAS - 1){
                            string celda = "│ " + valCelda + " ";
                            Graphics.print_completo("╤═══", Xinicial + (j*4), Yinicial, color);
                            Graphics.print_completo(celda, Xinicial + (j*4), Yinicial + 1, color);
                            Graphics.print_completo("┼───", Xinicial + (j*4), Yinicial + 2, color);
                        }
                        else {
                            string celda = "│ " + valCelda + " ║";
                            Graphics.print_completo("╤═══╗", Xinicial + (j*4), Yinicial);
                            Graphics.print_completo(celda, Xinicial + (j*4), Yinicial + 1);
                            Graphics.print_completo("┼───╢", Xinicial + (j*4), Yinicial + 2);
                        }
                    }

                    // Filas intermedias
                    else if (i < FILAS - 1){
                        string valCelda = mapa[i][j]->getEstado()->contenido;
                        
                        if (j == 0) {
                            string celda = "║ " + valCelda + " ";
                            Graphics.print_completo("╟───", Xinicial, Yinicial + (i*2), color);
                            Graphics.print_completo(celda, Xinicial, Yinicial + (i*2) + 1, color);
                            Graphics.print_completo("╟───", Xinicial, Yinicial + (i*2) + 2, color);
                        }
                        else if (j < COLUMNAS - 1){
                            string celda = "│ " + valCelda + " ";
                            Graphics.print_completo("┼───", Xinicial + (j*4), Yinicial + (i*2), color);
                            Graphics.print_completo(celda, Xinicial + (j*4), Yinicial + (i*2) + 1, color);
                            Graphics.print_completo("┼───", Xinicial + (j*4), Yinicial + (i*2) + 2, color);
                        }
                        else {
                            string celda = "│ " + valCelda + " ║";
                            Graphics.print_completo("┼───╢", Xinicial + (j*4), Yinicial+ (i*2), color);
                            Graphics.print_completo(celda, Xinicial + (j*4), Yinicial + (i*2) + 1, color);
                            Graphics.print_completo("┼───╢", Xinicial + (j*4), Yinicial + (i*2) + 2, color);
                        }
                    }
                    
                    // Ultima Fila
                    else {
                        string valCelda = mapa[i][j]->getEstado()->contenido;
                        if (j == 0) {
                            string celda = "║ " + valCelda + " ";
                            Graphics.print_completo("╟───", Xinicial, Yinicial + (i*2), color);
                            Graphics.print_completo(celda, Xinicial, Yinicial + (i*2) + 1, color);
                            Graphics.print_completo("╚═══", Xinicial, Yinicial + (i*2) + 2, color);
                        }
                        else if (j < COLUMNAS - 1){
                            string celda = "│ " + valCelda + " ";
                            Graphics.print_completo("┼───", Xinicial + (j*4), Yinicial + (i*2), color);
                            Graphics.print_completo(celda, Xinicial + (j*4), Yinicial + (i*2) + 1, color);
                            Graphics.print_completo("╧═══", Xinicial + (j*4), Yinicial + (i*2) + 2, color);
                        }
                        else {
                            string celda = "│ " + valCelda + " ║";
                            Graphics.print_completo("┼───╢", Xinicial + (j*4), Yinicial+ (i*2), color);
                            Graphics.print_completo(celda, Xinicial + (j*4), Yinicial + (i*2) + 1, color);
                            Graphics.print_completo("╧═══╝", Xinicial + (j*4), Yinicial + (i*2) + 2, color);
                        }
                    }
                }
            }
        }

        // Regresar un los vagones disponibles
        vector<rutaComponente> getRutasDisponibles(){
            vector<rutaComponente> rutasDisponibles;
            for (const auto& ruta : rutasDefinidas){
                if (ruta.estado == 0){
                    rutasDisponibles.push_back(ruta);
                }
            }
            return rutasDisponibles;
        }

        // Establece una ruta como ocupada
        void setRuta(int id, string color){
            for (auto& ruta : rutasDefinidas){
                if (ruta.id == id){
                    ruta.estado = 1;
                    ruta.color = color;
                    for (const auto& pos : ruta.posiciones){
                        mapa[pos.y - 1][pos.x - 1]->setEstado("█", ruta.color, 1);
                    }
                    break;
                }
            }
        }
};

