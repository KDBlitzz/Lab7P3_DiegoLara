#pragma once
#include <iostream>
#include <string>
using namespace std;
class CuentaBancaria
{
private:
	double balance;
	int numeroDeCuenta;
	string nombre;
public:
	CuentaBancaria(double balance, int numeroDeCuenta, string nombre);
	double getBalance();
	int getNumeroDeCuenta();
	string getNombre();
	void setBalance(double balance);
	void setNumeroDeCuenta(int numneroDeCuenta);
	void setNombre(string nombre);
	~CuentaBancaria();
	virtual void depositar(double monto);
	virtual void retirar(double monto);
	virtual void to_String();
};

