#include <iostream>
using namespace std;
void ejercicio_1() {

}
void menu() {
	int option = 0;
	bool menu = true;
	while (menu) {
		cout << "Ejercicio Práctico 1 – Simulación de Banco " << endl;
		cout << "2. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	menu();
}