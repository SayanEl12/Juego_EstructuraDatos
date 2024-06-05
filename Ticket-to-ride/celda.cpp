#include <iostream>
#include <string>
#include <map>

using namespace std;

class Celda {
    private:
    struct Componentes {
        string contenido;
        string color;
        int estado;
    };
    Componentes* comp = new Componentes;

    public:
    // Inicializar la celda
    Celda(string contenido_ = " ", string color_ = "WHITE", int estado_ = 0){
        comp->contenido = contenido_;
        comp->color = color_;
        comp->estado = estado_;
    }
    // Actualizar los elementos de la celda
    void setEstado(string contenido_ , string color_, int estado_){
        comp->contenido = contenido_;
        comp->color = color_;
        comp->estado = estado_;
    }
    // Regresar los elementos de la celda
    Componentes* getEstado(){
        return comp;
    }
};