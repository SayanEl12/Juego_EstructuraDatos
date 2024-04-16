#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Creacion de tablero
class Tablero{
	private:
        int inicial = 3;
		int colums = 13;
		int filas = 11;
		// creacion de tablero vacio
		string tablero[11][13];
	public:
        Tablero(){
            int i;
            int j;
            for (i = 0; i < filas; i ++){
                for (j = 0; j < colums; j++){
                    // Limite de valores a poder ingresar
                    vector<int> limt = getLimit(colums, i, inicial);
                    //cout<<'['<<limt[0]<<','<<limt[1]<<']';
                    if (j > limt[0] && j < limt[1]){
                        tablero[i][j] = " _ ";
                    }
                    else {tablero[i][j] = "   ";}
                }
            //cout<<endl;
            }
        }
        
        vector<int> getLimit(int largo, int iter, int min = 0){
            int mitad = floor(largo/2);
            int limInf;
            int limSup;
            iter = iter + 1 + floor(min/2);
            if (iter <= mitad+1){
                limInf = mitad - iter;
                limSup = mitad + iter;
                vector<int> limits = {limInf, limSup};
                return limits;
            }
            else {
                int dif = -iter + largo+1;
                limInf = mitad - dif;
                limSup = mitad + dif;
                vector<int> limits = {limInf, limSup};
                return limits;
            }
        }
        
        void añadir(int fila, int objeto){
            tablero[fila];
        }
        
		void mostrar(){
			for (int i = 0; i < filas; i++){
				for(int j = 0; j < colums; j++){
					cout << tablero[i][j];
				};
				cout<< i+2<<endl;
			};
		}
};

int main(){
	
	Tablero tablero_1 = Tablero();
	tablero_1.mostrar();
	return 0;
}
