#pragma once
#include "CuentaBancaria.h"
class CuentaAhorro : public CuentaBancaria
{
private:
	double tasaDeInteres;
public:
	CuentaAhorro(double balance, int numeroDeCuenta, string nombre, double tasaDeInteres);
	double gettasaDeInteres();
	void settasaDeInteres(double tasaDeInteres);
	void depositar(double monto);
	void retirar(double monto);
	~CuentaAhorro();
};

