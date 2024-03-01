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
	bool verificar = false;
	bool verificarDeposito = false;
	bool verificarRetiro = false;
	double cantDeposito = 0.0;
	double cantRetirar = 0.0;
	int selecDeposito = 0;
	vector<CuentaBancaria*> cuentas;
	BancoLCF* administrador = new BancoLCF(cuentas);
	bool ejercicio1 = true;
	int opcion = 0;
	int eliminar = 0;
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
			while (selecCuenta < 1 || selecCuenta > 2)
			{
				cout << "Elija 1 o 2" << endl;
				cin >> selecCuenta;
			}
			cout << "\nNumero de Cuenta: "; cin >> numeroCuenta;
			while (numeroCuenta < 1000 || numeroCuenta > 9999) {
				cout << "Ingrese un numero de cuenta entre 1000 y 9999" << endl;
				cin >> numeroCuenta;
			}
			for (int i = 0; i < administrador->getcuentas().size(); i++)
			{
				while (administrador->getcuentas()[i]->getNumeroDeCuenta() == numeroCuenta)
				{
					cout << "Ese numero de cuenta ya existe, favor ingrese otro" << endl;
					cin >> numeroCuenta;
					break;
				}
				while (numeroCuenta < 1000 || numeroCuenta > 9999) {
					cout << "Ingrese un numero de cuenta entre 1000 y 9999" << endl;
					cin >> numeroCuenta;
				}
			}
			cout << "\nNombre del Propetario: "; cin >> nombre;
			cout << "\nSaldo Inicial: "; cin >> saldo;
			while (saldo < 0 || saldo > 100000) {
				cout << "Ingrese un saldo entre 0 y 100000" << endl;
				cin >> saldo;
			}
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
			else if (selecCuenta == 2) {
				cout << "Sobregiro: "; cin >> sobregiro;
				while (sobregiro < 100.0 || sobregiro > 350.0) {
					cout << "Ingrese un sobregiro con un valor entre 100 y 350" << endl;
					cin >> sobregiro;
				}
				cout << endl;
				CuentaCheque* chequeNuevo = new CuentaCheque(saldo, numeroCuenta, nombre, sobregiro);
				administrador->agregarCuenta(chequeNuevo);
			}
			break;
		case 2:
			if (administrador->getcuentas().empty())
			{
				cout << "No hay ninguna cuenta" << endl;
			}
			else {
				administrador->mostrarCuentas();
				cout << "Seleccione el numero de cuenta de la cuenta a la que desea depositar: "; cin >> selecDeposito;
				for (int i = 0; i < administrador->getcuentas().size(); i++)
				{
					if (administrador->getcuentas()[i]->getNumeroDeCuenta() == selecDeposito)
					{
						verificarDeposito = true;
					}
				}

				if (!verificarDeposito)
				{
					cout << "Esa cuenta no existe" << endl;
					break;
				}
				else {
					cout << "Cantidad a depositar: "; cin >> cantDeposito;
					while (cantDeposito < 0) {
						cout << "Ingrese un numero mayor a 0" << endl;
						cin >> cantDeposito;
					}
					cout << endl;
					Transaccion<CuentaBancaria>* transaccion = new Transaccion<CuentaBancaria>();
					transaccion->ejecutarTransaccion();
				}
			}
			break;
		case 3:
			if (administrador->getcuentas().empty())
			{
				cout << "No hay ninguna cuenta" << endl;
			}
			else {
				administrador->mostrarCuentas();
			}
			break;
		case 4:
			administrador->mostrarCuentas();
			break;
		case 5:
			if (administrador->getcuentas().empty())
			{
				cout << "No hay ninguna cuenta" << endl;
			}
			else {
				administrador->mostrarCuentas();
				cout << "Seleccione el numero de cuenta de la cuenta que desea eliminar: "; cin >> eliminar;
				for (int i = 0; i < administrador->getcuentas().size(); i++)
				{
					if (administrador->getcuentas()[i]->getNumeroDeCuenta() == eliminar)
					{
						verificar = true;
					}
				}

				if (!verificar)
				{
					cout << "Esa cuenta no existe" << endl;
					break;
				}
				else {
					administrador->eliminarCuenta(eliminar);
				}
			}
			break;
		case 6:
			ejercicio1 = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
void menu() {
	int option = 0;
	bool menu = true;
	while (menu) {
		cout << "Ejercicio Pr�ctico 1 � Simulaci�n de Banco " << endl;
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