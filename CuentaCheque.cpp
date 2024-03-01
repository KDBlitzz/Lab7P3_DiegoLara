#include "CuentaCheque.h"

CuentaCheque::CuentaCheque(double balance, int numeroDeCuenta, string nombre, double sobregiro)
	: CuentaBancaria(balance, numeroDeCuenta, nombre)
{
	this->sobregiro = sobregiro;
	this->confirmarSobreGiro = confirmarSobreGiro;
}

double CuentaCheque::getsobregiro()
{
	return sobregiro;
}

void CuentaCheque::setsobregiro(double sobregiro)
{
	this->sobregiro = sobregiro;
}

void CuentaCheque::depositar(double monto)
{
	this->setBalance(this->getBalance() + monto);
	if (confirmarSobreGiro)
	{
		this->setBalance(this->getBalance() - sobregiro);
		cout << "Tarifa por sobregiro de " << sobregiro << " aplicado." << endl;
	}
	cout << "Depositado: " << monto << endl;
	cout << "Deposito realizado correctamente." << endl;
}

void CuentaCheque::retirar(double monto)
{
	this->setBalance(this->getBalance() - monto);
	if (this->getBalance() < monto)
	{
		confirmarSobreGiro = true;
		cout << "Retiro realizado correctamente con tarifa." << endl;
	}
	else {
		confirmarSobreGiro = false;
		cout << "Retiro realizado correctamente sin tarifa." << endl;
	}
}

CuentaCheque::~CuentaCheque()
{
	sobregiro = 0.0;
}

void CuentaCheque::to_String()
{
	CuentaBancaria::to_String();
	cout << "Tipo de Cuenta: Cheque" << endl;
	cout << "Sobregiro: $" << this->sobregiro << endl;
}
