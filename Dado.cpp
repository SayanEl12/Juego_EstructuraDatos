#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
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

int main(){
    
    Dado dado;
    
    dado.lanzarDados();
    dado.mostrarDados();
    dado.retornarPares();
    
}
