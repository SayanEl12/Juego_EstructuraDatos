#include <iostream>
#include <vector>
//ya lo estoy implementando en una clase y ya seria vector<vector<Ficha>> tablero, solo que falta que tenga una columna mas de 11 de las 3 que son iguales
using namespace std;

int main() {
    vector<vector<int>> tablero;

    int longitudes[] =  {1, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3, 1};

    for (int i = 0; i < 13; ++i) {
        vector<int> fila;
        int espaciosInicio = (15 - longitudes[i]) / 2;
        int espaciosFin = 15 - longitudes[i] - espaciosInicio;

        for (int j = 0; j < espaciosInicio; ++j) {
            fila.push_back(-1);
        }

        for (int j = 1; j <= longitudes[i] - 1; ++j) { // No agregar el "1" en la primera fila
            fila.push_back(j);
        }

        for (int j = 0; j < espaciosFin; ++j) {
            fila.push_back(-1);
        }

        if (i == 12) {
            fila.erase(fila.begin() + 1); 
        }

        tablero.push_back(fila);
    }

    for (const auto& fila : tablero) {
        for (const auto& casilla : fila) {
            if (casilla == -1) {
                cout << "  "; 
            } else {
                cout << casilla << " "; 
            }
        }
        cout << endl;
    }

    return 0;
}
