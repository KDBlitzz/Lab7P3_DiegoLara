#include "CuentaCheque.h"

CuentaCheque::CuentaCheque(double balance, int numeroDeCuenta, string nombre, double sobregiro)
	: CuentaBancaria(balance, numeroDeCuenta, nombre)
{
	this->sobregiro = sobregiro;
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
}

void CuentaCheque::retirar(double monto)
{
}

CuentaCheque::~CuentaCheque()
{
	sobregiro = 0.0;
}
