#include <iostream>
#include <string>
#include <map>

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
};