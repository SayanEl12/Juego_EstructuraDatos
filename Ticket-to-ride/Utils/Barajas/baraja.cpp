#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> 
#include <ctime>
using namespace std;
class ZonaCarta;
class Baraja{
    public:
        stack<char> mazo;
        stack<char> descarte;
        void barajar(vector<char>& cartas){
            srand(time(NULL)); 
            random_shuffle(cartas.begin(), cartas.end());
        }

        Baraja() {
            vector<char> colores = {'v', 'a', 'r', 'm', 'c', 'n'};
            vector<char> cartas;

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

        vector<char> robarCarta() {
            vector<char> cartas3(3, '\0');
            if (mazo.empty()) {
                if (descarte.empty()) {
                    return cartas3;
                } else {
                    trancisionDescarte_Baraja();
                    for (int i = 0; i < 3; ++i) {
                        if (!descarte.empty()) {
                            cartas3[i] = descarte.top();
                            descarte.pop();
                        }
                    }
                    vector<char> cartas(cartas3.begin(), cartas3.end());
                    barajar(cartas);
                    for (const auto& carta : cartas) {
                        mazo.push(carta);
                    }
                }
            } else {
                for (int i = 0; i < 3; ++i) {
                    if (!mazo.empty()) {
                        cartas3[i] = mazo.top();
                        mazo.pop();
                    }
                }
            }
            return cartas3;
        }

        bool confirmarMazo() {
            return !mazo.empty();
        }

        void trancisionDescarte_Baraja() {
            while (!descarte.empty()) {
                mazo.push(descarte.top());
                descarte.pop();
            }
        }
};

class ZonaCarta {
public:
    vector<char> zona;

    ZonaCarta(Baraja* b) : zona(4, '\0') {
        for (int i = 0; i < 4; ++i) {
            if (!b->confirmarMazo()) {
                b->trancisionDescarte_Baraja();
            }
            if (!b->mazo.empty()) {
                zona[i] = b->mazo.top();
                b->mazo.pop();
            }
        }
    }
    
    void rellenarZona(Baraja* b) {
        for (int i = 0; i < 4; ++i) {
            if (zona[i] == '\0') {
                if (!b->confirmarMazo()) {
                    b->trancisionDescarte_Baraja();
                }
                if (!b->mazo.empty()) {
                    zona[i] = b->mazo.top();
                    b->mazo.pop();
                }
            }
        }
    }
    
    void mostrarZona() {
        
        if (zona.empty()) {
            cout << "Zona vacía" << endl;
            cout <<"rellenando zona de cartas"<<endl;
        } else {
            cout << "Carta 1: " << zona[0] << " Carta 2: " << zona[1] << " Carta 3: " << zona[2] << " Carta 4: " << zona[3] << endl;
        }
    }

    vector<char> escogerCartas(Baraja* b){
        //mostrarZona();
        bool confirmacion = false;
        while (!confirmacion) {
            bool zonaLlena = true;
            for (const auto& carta : zona) {
                if (carta == '\0') {
                    zonaLlena = false;
                    break;
                }
            }
            if (zonaLlena) {
                confirmacion = true;
            } else {
                rellenarZona(b);
            }
        }
        return zona;
    }
};



