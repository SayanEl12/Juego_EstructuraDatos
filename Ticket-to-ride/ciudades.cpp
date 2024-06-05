#include <vector>
#include <string>
using namespace std;

struct posicionCiu {
    int x;
    int y;
};

struct ciudadesComponentes {
    string nombre;
    vector<posicionCiu> posiciones;
};

vector<ciudadesComponentes> ciudades = {
    {"A", {{1, 8}}},
    {"B", {{3, 5}}},
    {"C", {{3, 14}}},
    {"D", {{4, 1}}},
    {"E", {{6, 5}}},
    {"F", {{6, 8}}},
    {"G", {{6, 12}}},
    {"H", {{9, 8}}},
    {"I", {{10, 5}}},
    {"J", {{11, 2}}},
    {"K", {{12, 8}}},
    {"L", {{12, 12}}},
    {"M", {{13, 14}}},
    {"N", {{14, 2}}},
    {"O", {{16, 4}}},
    {"P", {{16, 8}}},
    {"Q", {{16, 12}}},
    {"R", {{19, 5}}},
    {"S", {{19, 10}}}
};
