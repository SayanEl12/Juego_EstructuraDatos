#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Creacion de tablero
class Tablero{
	public:
		int inicial = 3;
		int max_row = 11;
		int max_col = 13;
		int mitad = 7;
		char tablero[11][13];
		Tablero(){
			for (int i = 0; i < max_row;i++){
				for(int j = 0; j < max_col; j++){
					int lim_exp = ceil((inicial + i*2)/2);
					int min_mitad = mitad - lim_exp;
					int max_mitad = mitad + lim_exp;
					//cout << min_mitad << endl;
					if (j > min_mitad && j < max_mitad){
						tablero[i][j] = '*';
					}else{
						tablero[i][j] = '_';
					}
				};
			};
		}
		void mostrar(){
			for (int i = 0; i < max_row; i++){
				for(int j = 0; j < max_col; j++){
					cout << tablero[i][j];	
				};
				cout<<endl;
			};
		}
};

int main(){
	
	Tablero tablero_1 = Tablero();
	tablero_1.mostrar();
	return 0;
}
