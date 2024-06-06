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
public:
  Jugador(int id);
  void robarCarta(Carta carta);
  void obtenerDosCartas(vector<Carta> &baraja);
  void descartarCarta(Color color, int cantidad, vector<Carta> &descarte);
  int contarCartas(Color color);
  void usarVagones(int cantidad);
  void agregarPuntos(int puntos);
  bool tieneVagonesDisponibles() const;
  void mostrarEstado() const;
  void organizarCartasPorColor();
  bool realizarTrayecto(int cantidadCartas, Color color,vector<Carta> &descarte);

private:
  int id;
  vector<Carta> mano;
  int vagones;
  int puntos;
};

Jugador::Jugador(int id) : id(id), vagones(18), puntos(0) {}

void Jugador::robarCarta(Carta carta) { mano.push_back(carta); }

void Jugador::obtenerDosCartas(vector<Carta> &baraja) {
  for (int i = 0; i < 2; ++i) {
    if (!baraja.empty()) {
      robarCarta(baraja.back());
      baraja.pop_back();
    } else {
      cout << "No hay suficientes cartas en la baraja para robar."<< endl;
      break;
    }
  }
}

void Jugador::descartarCarta(Color color, int cantidad,vector<Carta> &descarte) {
  int cont = 0;
  auto it = mano.begin();
  while (it != mano.end() && cont < cantidad) {
    if (it->color == color) {
      descarte.push_back(*it);
      it = mano.erase(it);
      cont++;
    } else {
      ++it;
    }
  }
}

int Jugador::contarCartas(Color color) {
  return count_if(mano.begin(), mano.end(),[color](Carta carta) { return carta.color == color; });
}

void Jugador::usarVagones(int cantidad) {
  if (vagones >= cantidad) {
    vagones -= cantidad;
  }
}

void Jugador::agregarPuntos(int puntos) { this->puntos += puntos; }

bool Jugador::tieneVagonesDisponibles() const { return vagones >= 5; }

void Jugador::mostrarEstado() const {
  cout << "Jugador " << id << ": " << vagones << " vagones, " << puntos << " puntos, " << mano.size() << " cartas en mano." << endl;
}

void Jugador::organizarCartasPorColor() {
  sort(mano.begin(), mano.end(),
            [](const Carta &a, const Carta &b) { return a.color < b.color; });
}

bool Jugador::realizarTrayecto(int cantidadCartas, Color color,vector<Carta> &descarte) {
  int cartasDisponibles = contarCartas(color);

  if (cartasDisponibles >= cantidadCartas) {
    descartarCarta(color, cantidadCartas, descarte);
    usarVagones(cantidadCartas);

    
    switch (cantidadCartas) {
    case 2:
      agregarPuntos(1);
      break;
    case 3:
      agregarPuntos(2);
      break;
    case 4:
      agregarPuntos(4);
      break;
    case 5:
      agregarPuntos(6);
      break;
    case 6:
      agregarPuntos(9);
      break;
    }

    return true;
  } else {cout << "No tienes suficientes cartas para realizar este trayecto."<< endl;
    return false;
  }
}


