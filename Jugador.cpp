#include <iostream>
#include <vector>
using namespace std;

class Jugador {
private:
  vector<int> exploradoras; // Vector para almacenar las fichas exploradoras
  vector<int> guardianes;   // Vector para almacenar las fichas guardianes
  int id;                   // Identificador del jugador

public:
  Jugador(int jugadorID) : id(jugadorID) {
    // Inicializar las fichas exploradoras (3) y guardianes (10)
    for (int i = 0; i < 3; ++i) {
      exploradoras.push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
      guardianes.push_back(i);
    }
  }

  void moverExploradora(int fichaID, int nuevaPosicion) {
    cout << "El jugador " << id << " movió la ficha exploradora " << fichaID
         << " a la posición " << nuevaPosicion << endl;
  }
};

int main() {

  Jugador jugador1(1);
  Jugador jugador2(2);

  jugador1.moverExploradora(0, 5);
  jugador2.moverExploradora(1, 3);

  return 0;
}