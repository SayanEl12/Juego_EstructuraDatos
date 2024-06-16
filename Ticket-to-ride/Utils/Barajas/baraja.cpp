#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> 
#include <ctime>
using namespace std;
class ZonaCarta;

class Baraja{
    private:
        vector<string> colores = {"GREEN", "YELLOW", "RED", "MAGENTA", "BLUE", "ROSE"};
        stack<string> mazo;
        vector<string> descarte;
    public:
        Baraja() {
            vector<string> cartas;

            for (const auto& color : colores) {
                for (int i = 0; i < 12; ++i) {
                    cartas.push_back(color);
                }
            }

            barajar(cartas);

            for (const auto& carta : cartas) {
                mazo.push(carta);
            }
        }

        void barajar(vector<string>& cartas){
            srand(time(NULL)); 
            random_shuffle(cartas.begin(), cartas.end());
        }

        void addDescarte(string color, int cantidad){
            for (int i = 0; i < cantidad; i++){
                descarte.push_back(color);
            }
        }

        string robarCarta() {
            if (isMazoVacio()) {
                rellenarBarajaConDescartes();
            }
            string topCarta = mazo.top();
            mazo.pop();
            return topCarta;
        }

        bool isMazoVacio() {
            return mazo.empty();
        }

        void rellenarBarajaConDescartes() {
            barajar(descarte);
            for (int i = 0; i < descarte.size(); i++){
                mazo.push(descarte[i]);
            }
            descarte.clear();
        }
};

class ZonaCarta {
    private:
        vector<string> zona;
        Baraja* baraja;
    public:
        ZonaCarta(Baraja* b) : zona(4, "") {
            baraja = b;
            rellenarZona();
        }
        
        void rellenarZona() {
            for (int i = 0; i < 4; ++i) {
                if (zona[i] == "") {
                    if (baraja->isMazoVacio()) {
                        baraja->rellenarBarajaConDescartes();
                    }
                    else{
                        zona[i] = baraja->robarCarta();
                    }
                }
            }
        }

        vector<string> mostrarCartas(){
            return zona;
        }

        void robarCarta(int posicion){
            zona[posicion] = "";
            rellenarZona();
        }
};



