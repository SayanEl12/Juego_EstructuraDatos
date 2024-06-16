#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
#include <Windows.h>
#include <map>
#include <vector>

using namespace std;

class Graphics {
	private:
		map <string, string> colores;
		
	public:
		Graphics() {
			colores["RED"] = "\x1b[31m";
			colores["GREEN"] = "\x1b[32m";
			colores["BLUE"] = "\x1b[34m";
			colores["MAGENTA"] = "\x1b[35m";
			colores["ROSE"] = "\x1B[38;2;255;151;203m";
			colores["ORANGE"] = "\x1B[38;2;255;128;0m";
			colores["YELLOW"] = "\x1b[33m";
			colores["WHITE"] = "\x1B[37m";
		}
		map<string, string> getColores(){
			return colores;
		}

		void print_completo(const string& text, int x, int y, const string& color = "WHITE") {
			string colorCode = "\033[" + to_string(y) + ";" + to_string(x) + "H";  // Posiciona el cursor
			colorCode += colores[color];  // Establece el color RGB

			cout << colorCode << text << "\033[0m";
		}

		void limpiar_pantalla() {
			system("cls");
		}

		int select_opciones(const string& text, const map<string, int>& opciones, int first_pos_y, int first_pos_x) {
			enum Key {
				KEY_W = 119,
				KEY_S = 115,
				KEY_ENTER = 13
			};
			int maxLength = 0;
			int pos_y = first_pos_y;
			int pos_x = first_pos_x;
			int count = 0;

			// Imprime el texto inicial
			print_completo(text, first_pos_x, first_pos_y - 2);

			// Encuentra la longitud máxima de las opciones y las imprime
			for (const auto& option : opciones) {
				print_completo(option.first, first_pos_x, pos_y + count);
				if (option.first.length() > maxLength) {
					maxLength = option.first.length();
				}
				++count;
			}

			// Calcula la posición x para el indicador "<<" y lo imprime en la posición inicial
			pos_x += maxLength + 1;
			print_completo("<<", pos_x, pos_y, "ORANGE");

			// Bucle de selección
			while (true) {
				char key = _getch();

				switch (static_cast<int>(key)) {
					case KEY_W: // Tecla 'w'
						if (pos_y > first_pos_y) {
							print_completo("  ", pos_x, pos_y, "ORANGE"); // Borra el indicador actual
							--pos_y;
						}
						break;
					case KEY_S: // Tecla 's'
						if (pos_y < first_pos_y + static_cast<int>(opciones.size()) - 1) {
							print_completo("  ", pos_x, pos_y, "ORANGE"); // Borra el indicador actual
							++pos_y;
						}
						break;
					case KEY_ENTER: // Tecla Enter
						auto opcionActual = opciones.begin();
						advance(opcionActual, pos_y - first_pos_y);
						return opcionActual->second;
				}
				// Imprime el indicador en la nueva posición
				print_completo("<<", pos_x, pos_y, "ORANGE");
			}

			return 0; // No debería llegar aquí
		}
	
		void print_cartas(string value, int x_init, int y_init, string color){
			print_completo("╔═══╗", x_init, y_init, color);

			print_completo("║   ║", x_init, y_init + 1, color);
			print_completo(value, x_init + 2, y_init + 1, color);
			print_completo("╟───╢", x_init, y_init + 2, color);

			print_completo("╚═══╝", x_init, y_init + 3, color);
		}

		int esperar(){
			while(true){
				char key = _getch();
				if (key){
					return 0;		
				}
			}
		}
};