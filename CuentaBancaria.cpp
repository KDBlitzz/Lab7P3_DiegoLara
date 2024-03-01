#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria(double balance, int numeroDeCuenta, string nombre)
{
	this->balance = balance;
	this->numeroDeCuenta = numeroDeCuenta;
	this->nombre = nombre;
}

double CuentaBancaria::getBalance()
{
	return balance;
}

int CuentaBancaria::getNumeroDeCuenta()
{
	return numeroDeCuenta;
}

string CuentaBancaria::getNombre()
{
	return nombre;
}

void CuentaBancaria::setBalance(double balance)
{
	this->balance = balance;
}

void CuentaBancaria::setNumeroDeCuenta(int numneroDeCuenta)
{
	this->numeroDeCuenta = numeroDeCuenta;
}

void CuentaBancaria::setNombre(string nombre)
{
	this->nombre = nombre;
}

CuentaBancaria::~CuentaBancaria()
{
	balance = 0.0;
	numeroDeCuenta = 0;
	nombre = "";
}

void CuentaBancaria::depositar(double monto)
{
}

void CuentaBancaria::retirar(double monto)
{
}

void CuentaBancaria::to_String()
{
	cout << "Balance: $" << this->balance << endl;
	cout << "Numero de Cuenta: " << this->numeroDeCuenta << endl;
	cout << "Nombre: " << this->nombre << endl;
}
