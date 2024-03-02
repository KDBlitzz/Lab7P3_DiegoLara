#include "CuentaAhorro.h"

CuentaAhorro::CuentaAhorro()
{
}

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
	bono = (this->gettasaDeInteres() / 100) * monto; // conversion del bono
	double total = 0;
	total = monto + bono;
	this->setBalance(this->getBalance() + total); // depositar
	cout << "Depositado: " << monto << " con bono: " << bono << endl;
	cout << "Deposito realizado correctamente." << endl; 
}

void CuentaAhorro::retirar(double monto)
{
	while (this->getBalance() < monto) { // validar
		cout << "El monto que quiere retirar es mayor al balance que tiene. Favor ingresar otro monto: "; 
		cin >> monto;
		cout << endl;
	}
	this->setBalance(this->getBalance() - monto); // retirar
	cout << "Retiro realizado correctamente." << endl;
}

CuentaAhorro::~CuentaAhorro()
{
	//tasaDeInteres = 0.0;
}

void CuentaAhorro::to_String()
{
	CuentaBancaria::to_String(); 
	cout << "Tipo de Cuenta: Ahorro" << endl;
	cout << "Tasa de Interes: " << this->tasaDeInteres << "%" << endl;
}

