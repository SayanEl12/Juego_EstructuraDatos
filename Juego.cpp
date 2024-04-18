#include <iostream>
#include <vector>
#include <cmath>
#include <string>
//#include <dado>
using namespace std;

//Creacion de tablero
class Tablero{
	private:
        int inicial = 3;
		int x = 13;
		int y = 11;
		// creacion de tablero vacio
		vector<vector<string>> tablero;
			
	public:
        Tablero(){
            int i;
            int j;
            for (i = 0; i < y; i++){
            	int size_ = size(y, i, inicial);
            	
            	vector<string> row(size_, " _ ");
            	tablero.push_back(row);
			}
        }
        
        int size(int rows, int i, int min = 1){
        	int mitad = floor(rows/2);
        	int rowLong;
        	if (i <= mitad){
        		rowLong = i*2 + min;
			}else{
				rowLong = (rows - i - 1) * 2 + min;
			}
			return rowLong;
		}
                
        void add(int fila, string objeto){
        	int place = tablero[fila-2].capacity();
        	place = place - (place + 1);
        	tablero[fila-2][place+1] = objeto;
        }
        
		void mostrar(){
			int size;
			for (int i = 0; i < y; i++){
				size = tablero[i].size();
				int max = tablero[y/2].size();
				int espacios = (max-size)/2;
				for(int esp = 0; esp < espacios; esp++) {cout << "   ";}
				for(int j = 0; j < size; j++){
					cout << tablero[i][j];
				};
				cout<< i+2<<endl;
			};
		}
};

int main(){
	
	Tablero tablero_1 = Tablero();
	tablero_1.add(9, " X ");
	tablero_1.add(3, " X ");
	tablero_1.mostrar();
	return 0;
}
	
	Tablero tablero_1 = Tablero();
	tablero_1.mostrar();
	return 0;
}
