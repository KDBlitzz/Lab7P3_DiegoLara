#pragma once
#include <iostream>
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
	Transaccion(T* cuentaBancaria, double monto, string tipo) {
		this->cuentaBancaria = cuentaBancaria;
		this->monto = mono;
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
	void ejecutarTransaccion() {

	}
};

