#pragma once
#include <iostream>
#include "CuentaBancaria.h"
#include <string>
using namespace std;
template <typename T>
class Transaccion
{
private:
	T* cuentaBancaria;
	double monto;
	string tipo;
public:
	Transaccion() {};
	Transaccion(T* cuentaBancaria, double monto, string tipo)  {
		this->cuentaBancaria = cuentaBancaria;
		this->monto = monto;
		this->tipo = tipo;
	}
	T* getcuentaBancaria() {
		return cuentaBancaria;
	}
	double getmonto() {
		return monto;
	}
	string gettipo() {
		return tipo;
	}
	void setcuentaBancaria(T* cuentaBancaria) {
		this->cuentaBancaria = cuentaBancaria;
	}
	void setmonto(double monto) {
		this->monto = monto;
	}
	void settipo(string tipo) {
		this->tipo = tipo;
	}
	~Transaccion() {
		delete cuentaBancaria;
		monto = 0.0;
		tipo = "";
	}
	template <typename C>
	void ejecutarTransaccion() {
		if (this->gettipo() == "Depositar") {
			this->cuentaBancaria<C>->depositar(monto);
		}
		else if (this->gettipo() == "Retirar") {
			this->cuentaBancaria<C>->retirar(monto);
		}
	}
};

