using namespace std;
#include <iostream>
class Ficha{
    public:
    
    string estadoActual;
    
    Ficha Ficha(){
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
            return "x";
        }else{
            return "o";
        }
        
    }
    
};
