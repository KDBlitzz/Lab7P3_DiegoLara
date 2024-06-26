#pragma once
#include "CuentaBancaria.h"
class CuentaCheque : public CuentaBancaria
{
private:
	double sobregiro;
	bool confirmarSobreGiro = false;
public:
	CuentaCheque();
	CuentaCheque(double balance, int numeroDeCuenta, string nombre, double sobregiro);
	double getsobregiro();
	void setsobregiro(double sobregiro);
	void depositar(double monto);
	void retirar(double monto);
	~CuentaCheque();
	void to_String();
};

