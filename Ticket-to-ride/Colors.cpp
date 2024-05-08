#include <iostream>
#include <string>
#include <map>

using namespace std;

class Colors {
	private:
		map <string, string> colores;
		
	public:
		Colors() {
			colores["RED"] = "\x1b[31m";
			colores["GREEN"] = "\x1b[32m";
			colores["BLUE"] = "\x1b[34m";
			colores["MAGENTA"] = "\x1b[35m";
			colores["ORANGE"] = "\x1B[38;2;255;128;0m";
			colores["LBLUE"] = "\x1B[38;2;53;149;240m";
			colores["RESET"] = "\x1B[37m";
		}
		
		string printC(string text, string color) {
        	return colores[color] + text + colores["RESET"];
    	}
};

int main(){
	Colors Colors; 
	cout << Colors.printC("Hola que tal", "LBLUE") << endl;
	cout << Colors.printC("AZULLLL", "BLUE") << endl;
	
	return 0;
}
