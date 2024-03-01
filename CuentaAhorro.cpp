#include "CuentaAhorro.h"

CuentaAhorro::CuentaAhorro(double balance, int numeroDeCuenta, string nombre, double tasaDeInteres) :
	CuentaBancaria(balance, numeroDeCuenta, nombre)
{
	this->tasaDeInteres = tasaDeInteres;
}

double CuentaAhorro::gettasaDeInteres()
{
	return tasaDeInteres;
}

void CuentaAhorro::settasaDeInteres(double tasaDeInteres)
{
	this->tasaDeInteres = tasaDeInteres;
}

void CuentaAhorro::depositar(double monto)
{
	double bono = 0;
	bono = (this->gettasaDeInteres() / 100) * monto;
	double total = 0;
	total = monto + bono;
	this->setBalance(total);
}

void CuentaAhorro::retirar(double monto)
{
	while (this->getBalance() < monto) {
		cout << "El monto que quiere retirar es mayor al balance que tiene. Favor ingresar otro monto: "; 
		cin >> monto;
		cout << endl;
	}
	this->setBalance(this->getBalance() - monto);
}

CuentaAhorro::~CuentaAhorro()
{
	tasaDeInteres = 0.0;
}
