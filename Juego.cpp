#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
//#include <dado>
using namespace std;

// Clase ficha
class Ficha{
    public:
        string estadoActual;
        
        Ficha(){
            estadoActual = "explorador";
        }
        
        void cambiarTipo(){
             
            if (estadoActual == "explorador") {
                estadoActual = "guardian";
            }else{
                estadoActual = "explorador";
            }
        }
        
        string mostrar(){
            if(estadoActual == "explorador"){
                return " X ";
            }else{
                return " ۩ ";
            }
        }
    
};

// Clase de tablero
class Tablero{
	private:
        int inicial = 3;
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
                
        void add(int fila, Ficha ficha){
            bool isVoid = true;
        	int place = tablero[fila-2].capacity();
        	place = place - (place + 1);
        	
        	while (isVoid){
        	    if (tablero[fila-2][place+1] != " _ "){
        	        place ++;
        	    }else {isVoid = false;}
        	}
        	tablero[fila-2][place+1] = ficha.mostrar();
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
				cout<< "|"<<i+2<<endl;
			};
		}
};

// Clase dado
class Dado{
    public:
    int dados[4];
    int lanzamientos;
    
    Dado(): lanzamientos(0){
        srand(time(0));
        //roll();
    }
    
    int contLanzadas() {
        return lanzamientos;
    }
    
    void lanzarDados(){
        for(int i = 0;i<4;i++){
            dados[i] = rand() % 6 + 1;
        }
    }
    
    void mostrarDados(){
        for(int i = 0;i<4;i++){
            cout<<"r"<<i+1<<" "<<dados[i]<<endl;
        }
    }
    
    vector<int> retornarPares(){
        
        for(int i = 0;i<i;i++){
            cout<<dados[i]<<endl;
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
        if(choise == "r2"){
            par1 = r1 + r2;
            par2 = r3 + r4;
        }
        if(choise == "r3"){
            par1 = r1 + r3;
            par2 = r2 + r4;
        }
        if(choise == "r4"){
            par1 = r1 + r4;
            par2 = r2 + r3;
        }
        
        cout<<"par 1: "<<par1<<endl;
        cout<<"par 2: "<<par2<<endl;
        
        vector<int> parDados;
        parDados.push_back(par1);
        parDados.push_back(par2);
        
        return parDados;
        
    }
    
};

// Clase Juego
class juego{};

int main(){
	
	Tablero tablero_1 = Tablero();
	Ficha ficha_1, ficha_2, ficha_3;
	tablero_1.add(9, ficha_1);
	tablero_1.add(9, ficha_2);
	tablero_1.add(9, ficha_3);
	tablero_1.mostrar();
	Dado dado;
    
    dado.lanzarDados();
    dado.mostrarDados();
    dado.retornarPares();
	return 0;
}
