#include <iostream>
#include "Transaccion.h"
#include "BancoLCF.h"
#include "CuentaBancaria.h"
#include "CuentaAhorro.h"
#include "CuentaCheque.h"
using namespace std;
void ejercicio_1() {
	int selecCuenta = 0;
	int numeroCuenta = 0;
	double tasa = 0.0;
	double sobregiro = 0.0;
	string nombre = "";
	double saldo = 0.0;
	Transaccion<CuentaAhorro>* transaccion = new Transaccion<CuentaAhorro>();
	vector<CuentaBancaria*> cuentas;
	BancoLCF* administrador = new BancoLCF(cuentas);
	bool ejercicio1 = true;
	int opcion = 0;
	while (ejercicio1) {
		cout << "--- Banco LCF ---" << endl;
		cout << "1. Crear Cuenta" << endl;
		cout << "2. Realizar Deposito" << endl;
		cout << "3. Realizar Retiro" << endl;
		cout << "4. Mostrar Informacion de Cuenta" << endl;
		cout << "5. Eliminar Cuenta" << endl;
		cout << "6. Salir" << endl;
		cout << "Seleccione una opcion: "; cin >> opcion;
		cout << endl;
		switch (opcion) {
		case 1:
			cout << "Tipo de Cuenta (1: Ahorro, 2: Cheque): "; cin >> selecCuenta;
			cout << "\nNumero de Cuenta: "; cin >> numeroCuenta;
			cout << "\nNombre del Propetario: "; cin >> nombre;
			cout << "\nSaldo Inicial: "; cin >> saldo;
			if (selecCuenta == 1)
			{
				cout << "\nTasa de Interes (%): "; cin >> tasa;
				while (tasa < 10.0 || tasa > 20.0) {
					cout << "Favor ingrese una tasa de interes entre 10 y 20" << endl;
					cin >> tasa;
				}
				cout << endl;
				CuentaAhorro* ahorroNuevo = new CuentaAhorro(saldo, numeroCuenta, nombre, tasa);
				administrador->agregarCuenta(ahorroNuevo);
			}
			else if (selecCuenta == 2){
				cout << "Sobregiro: "; cin >> sobregiro;
				while (sobregiro < 100 || sobregiro > 350) {
					cout << "Ingrese un sobregiro con un valor entre 100 y 350" << endl;
					cin >> sobregiro;
				}
				cout << endl;
				CuentaCheque* chequeNuevo = new CuentaCheque(saldo, numeroCuenta, nombre, sobregiro);
			}
			break;
		case 2:
			
			break;
		case 3:

			break;
		case 4:
			administrador->mostrarCuentas();
			break;
		case 5:
			
			break;
		case 6:
			ejercicio1 = false;
			break;
		}
	}
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