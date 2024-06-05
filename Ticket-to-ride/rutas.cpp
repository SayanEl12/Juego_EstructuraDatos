#include <vector>
#include <string>
using namespace std;
struct posicion {
    int x;
    int y;
};

struct rutaComponente {
    int id;
    string color;
    vector<posicion> posiciones;
};

vector<rutaComponente> rutasDefinidas = {
    {
        1, "RED", {
            {2, 5},
            {1, 5},
            {1, 6},
            {1, 7}
        }
    },
    {
        2, "BLUE", {
            {2, 8},
            {3, 8},
            {4, 8},
            {5, 8}
        }
    },
    {
        3, "ROSE", {
            {5, 1},
            {6, 1},
            {6, 2},
            {6, 3},
        }
    },
    {
        4, "GREEN", {
            {6, 5},
            {6, 6},
            {6, 7},
        }
    },
    {
        5, "YELLOW", {
            {6, 9},
            {6, 10},
            {6, 11}
        }
    },
    {
        6, "ROSE", {
            {3, 13},
            {3, 12},
            {4, 12},
            {5, 12},
        }
    },
    {
        7, "YELLOW", {
            {7, 8},
            {8, 8},
        }
    },
    {
        8, "RED", {
            {9, 9},
            {9, 10},
            {9, 11},
            {9, 12},
            {10, 12},
            {11, 12},
        }
    },
    {
        9, "YELLOW", {
            {12, 9},
            {12, 10},
            {12, 11},
        }
    },
    {
        10, "BLUE", {
            {10, 8},
            {11, 8},
        }
    },
    {
        11, "MAGENTA", {
            {12, 7},
            {12, 6},
            {11, 6},
            {10, 6},
        }
    },
    {
        12, "BLUE", {
            {10, 4},
            {11, 4},
            {12, 4},
            {13, 4},
            {14, 4},
            {15, 4},
        }
    },
    {
        13, "ORANGE", {
            {12, 2},
            {13, 2},
        }
    },
    {
        14, "GREEN", {
            {16, 3},
            {16, 2},
            {15, 2},
        }
    },
    {
        15, "YELLOW", {
            {16, 5},
            {16, 6},
            {16, 7},
        }
    },
    {
        16, "GREEN", {
            {13, 8},
            {14, 8},
            {15, 8},
        }
    },
    {
        17, "GREEN", {
            {16, 9},
            {16, 10},
            {16, 11},
        }
    },
    {
        18, "MAGENTA", {
            {14, 14},
            {15, 14},
            {16, 14},
            {16, 13}
        }
    },
    {
        19, "MAGENTA", {
            {17, 4},
            {18, 4},
            {19, 4},
            {19, 5}
        }
    },
    {
        20, "ROSE", {
            {17, 12},
            {18, 12},
            {19, 12},
            {19, 11}
        }
    },
};