#include <iostream>
#include <string>
#include <Windows.h>
#include "graphics.cpp"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IONBF, 0);
    Graphics Graphics;
	Graphics.print_completo("╔══╤══╗", 10, 2, "RED");
	Graphics.print_completo("║  │  ║", 10, 3, "RED");
    Graphics.print_completo("╟──┼──╢", 10, 4, "RED");
    Graphics.print_completo("╚══╧══╝", 10, 5, "RED");
    int a;
    cin >> a;

    return 0;
}

