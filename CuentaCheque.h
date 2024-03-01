#pragma once
#include "CuentaBancaria.h"
class CuentaCheque : public CuentaBancaria
{
private:
	double sobregiro;
	bool confirmarSobreGiro;
public:
	CuentaCheque(double balance, int numeroDeCuenta, string nombre, double sobregiro, bool confirmarSobreGiro);
	double getsobregiro();
	void setsobregiro(double sobregiro);
	void depositar(double monto);
	void retirar(double monto);
	~CuentaCheque();
};

