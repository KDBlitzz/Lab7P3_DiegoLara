#include "CuentaCheque.h"

CuentaCheque::CuentaCheque(double balance, int numeroDeCuenta, string nombre, double sobregiro, bool confirmarSobreGiro)
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
	}
}

void CuentaCheque::retirar(double monto)
{
	this->setBalance(this->getBalance() - monto);
	if (this->getBalance() < monto)
	{
		confirmarSobreGiro = true;
	}
	else {
		confirmarSobreGiro = false;
	}
}

CuentaCheque::~CuentaCheque()
{
	sobregiro = 0.0;
}
