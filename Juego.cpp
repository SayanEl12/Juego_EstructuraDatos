#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

// Clase ficha
class Ficha {
public:
    string estadoActual;
    
    Ficha() {
        estadoActual = "explorador";
    }
    
    void cambiarTipo() {
        if (estadoActual == "explorador") {
            estadoActual = "guardian";
        } else {
            estadoActual = "explorador";
        }
    }
    
    string mostrar() {
        if (estadoActual == "explorador") {
            return " X ";
        } else {
            return " ۩ ";
        }
    }
};

// Clase de tablero
class Tablero {
private:
    int inicial = 5;
    int y = 11;
    vector<vector<string>> tablero;
    
public:
    Tablero() {
        int i;
        int j;
        for (i = 0; i < y; i++) {
            int size_ = size(y, i, inicial);
            
            vector<string> row(size_, " _ ");
            tablero.push_back(row);
        }
    }
    
    int size(int rows, int i, int min = 1) {
        int mitad = floor(rows / 2);
        int rowLong;
        if (i <= mitad) {
            rowLong = i * 2 + min;
        } else {
            rowLong = (rows - i - 1) * 2 + min;
        }
        return rowLong;
    }
    
    void add(int fila, const string& ficha) {
        bool isVoid = true;
        int place = tablero[fila - 2].capacity();
        place = place - (place + 1);
        
        while (isVoid) {
            if (tablero[fila - 2][place + 1] != " _ ") {
                place++;
            } else {
                isVoid = false;
            }
        }
        tablero[fila - 2][place + 1] = ficha;
    }
    
    void mostrar() {
        int size;
        for (int i = 0; i < y; i++) {
            size = tablero[i].size();
            int max = tablero[y / 2].size();
            int espacios = (max - size) / 2;
            
            for (int esp = 0; esp < espacios; esp++) {
                cout << "   ";
            }
            
            for (int j = 0; j < size; j++) {
                cout << tablero[i][j];
            }
            cout << "|" << i + 2 << endl;
        }
    }
    
    void resetExplores(){
    	for (int i = 0; i < tablero.size(); i++){
    		for (string& space : tablero[i]) {
		        if (space == " X ") {
		            space = " _ ";
		        }
		    }
		}
	}
};

// Clase dado
class Dado {
public:
    int dados[4];
    int lanzamientos;
    
    Dado() : lanzamientos(0) {
        srand(time(0));
        //roll();
    }
    
    int contLanzadas() {
        return lanzamientos;
    }
    
    void lanzarDados() {
        for (int i = 0; i < 4; i++) {
            dados[i] = rand() % 6 + 1;
        }
    }
    
    void mostrarDados() {
        for (int i = 0; i < 4; i++) {
            cout << "( r" << i + 1 << ": " << dados[i] << " )";
        }
        cout << endl;
    }
    
    vector<int> retornarPares() {
        for (int i = 0; i < i; i++) {
            cout << dados[i] << endl;
        }
        
        int r1, r2, r3, r4;
        r1 = dados[0];
        r2 = dados[1];
        r3 = dados[2];
        r4 = dados[3];
        
        string choise;
        cout << "con cual resultado quiere emparejar r1: " << endl;
        cin >> choise;
        
        int par1, par2;
        if (choise == "r2") {
            par1 = r1 + r2;
            par2 = r3 + r4;
        }
        if (choise == "r3") {
            par1 = r1 + r3;
            par2 = r2 + r4;
        }
        if (choise == "r4") {
            par1 = r1 + r4;
            par2 = r2 + r3;
        }
        
        cout << "par 1: " << par1 << endl;
        cout << "par 2: " << par2 << endl;
        
        vector<int> parDados;
        parDados.push_back(par1);
        parDados.push_back(par2);
        
        return parDados;
    }
};

// Clase jugador
class Jugador {
private:
    int id;
    
public:
    Jugador() : id(0) {} // Constructor predeterminado
    Jugador(int jugadorID) : id(jugadorID) {}
    
    vector<int> getMove(Dado& dado) {
        dado.lanzarDados();
        dado.mostrarDados();
        vector<int> parDados = dado.retornarPares();
        return parDados;
    }
};

// Clase Juego
class Juego {
private:
    vector<Jugador> players;
    Dado dado;
    const int NUM_MAX_EXPLORES = 3;
    
public:
    Juego() {
        players.resize(2);
        players[0] = Jugador(1); // Crear jugador 1
        players[1] = Jugador(2); // Crear jugador 2
        Tablero tablero;
        
        while (!anyWinner()) {
            for (int i = 0; i < players.size(); i++) {
                bool keepPlaying = true;
                cout << "====== PLAYER "<< i+1<<"======"<<endl;
                
                // filas por turnos
                set <int> busyRows;
                while (keepPlaying){
                    vector<int> moves = players[i].getMove(dado);
                    // añadir filas ocupadas
                    for (int move : moves){
                    	busyRows.insert(move);
					}
					// Revisa si hay mas filas que las que puede almacenar
					if (busyRows.size() > NUM_MAX_EXPLORES){
						cout << endl;
						cout << "     ===== EXEDISTE EL NUMERO DE EXPLORADORES=====" << endl;
						cout << endl;
						tablero.resetExplores();
						keepPlaying = false;
						continue;
					}
                    
                    Ficha ficha;
                    tablero.add(moves[0], ficha.mostrar());
                    tablero.add(moves[1], ficha.mostrar());
                    tablero.mostrar();
                    
                    string answer;
                    cout << "¿Va a pasar de turno? (si/no)" << endl;
                    cin >> answer;
                    if (answer == "si"){
                        
                        
                        keepPlaying = false;
                    }
                }
            }
        }
    }
    
    bool anyWinner() {
        return false;
    }
};

int main() {
    Juego juego;
    return 0;
}
