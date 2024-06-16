#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum Color { ROJO, AZUL, VERDE, MORADO, CAFE, NARANJA };

struct Carta {
  Color color;
};

class Jugador {
  private:
    int id;
    string color;
    map<string, int> cartasJug;
    int vagones;
    int puntos;
  public:
    Jugador(int id, string color) : id(id), vagones(18), puntos(0), color(color){}

    string getColor(){
      return color;
    }

    int getVagones(){
      return vagones;
    }
    
    int getID(){
      return id;
    }

    int getPuntos(){
      return puntos;
    }
    void addCarta(string color){
      if (cartasJug.count(color) > 0){
        cartasJug[color] = cartasJug[color] + 1;
      }else {
        cartasJug[color] = 1;
      }
      
    }

    void usarCartas(string color, int cantidad){
      cartasJug[color] = cartasJug[color] - cantidad;
      vagones -= cantidad;
    }

    map<string, int> getCartas(){
      return cartasJug;
    }

    void usarVagones(int cantidad) {
      if (vagones >= cantidad) {
        vagones -= cantidad;
      }
    }

    void agregarPuntos(int puntos) { this->puntos += puntos; }
};