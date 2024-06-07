#include <iostream>
#include <string>
#include <conio.h>
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

		void print_completo(const string& text, int x, int y, const string& color = "WHITE") {
			string colorCode = "\033[" + to_string(y) + ";" + to_string(x) + "H";  // Posiciona el cursor
			colorCode += colores[color];  // Establece el color RGB

			cout << colorCode << text << "\033[0m";
		}
		void limpiar_pantalla() {
			std::cout << "\033[2J\033[1;1H";
		}
		string select_opciones(string text, vector<string> opciones, int first_pos_y, int first_pos_x){
			int select = first_pos_y;
			int pos_x = first_pos_x + 15;

			print_completo(text, first_pos_x, first_pos_y - 2);

			for (int i = 0; i < opciones.size(); i++){
				print_completo(opciones[i], first_pos_x, select + i);
			}

			print_completo("<<", pos_x, select, "ORANGE");

			while(true){
				char key = _getch();

				switch ((int)key)
				/*
				115 corresponde a la tecla 's'.
				119 corresponde a la tecla 'w'.
				13 corresponde a la tecla Enter.*/
				{
				case 119:
					if (select > first_pos_y){
						select -= 1;
						print_completo("  ", pos_x, select + 1, "ORANGE");
					}
					break;
				case 115:
					if (select <first_pos_y + opciones.size() - 1){
						select += 1;
						print_completo("  ", pos_x, select - 1, "ORANGE");
					}
					break;
				case 13:
					return opciones[select - first_pos_y];
					break;
				}
				print_completo("<<", pos_x, select, "ORANGE");
			}	
			return 0;
		}

		void print_cartas(string value, int x_init, int y_init, string color){
			print_completo("╔═══╗", x_init, y_init, color);

			print_completo("║   ║", x_init, y_init + 1, color);
			print_completo(value, x_init + 2, y_init + 1, color);

			print_completo("╚═══╝", x_init, y_init + 2, color);
		}
};