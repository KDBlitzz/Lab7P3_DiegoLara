#pragma once
#include "CuentaBancaria.h"
#include <vector>
class BancoLCF
{
private:
	vector<CuentaBancaria*> cuentas;
public:
	BancoLCF(vector<CuentaBancaria*> cuentas);
	vector<CuentaBancaria*> getcuentas();
	void setcuentas(vector<CuentaBancaria*> cuentas);
	~BancoLCF();
	void agregarCuenta(CuentaBancaria* cuenta);
	void eliminarCuenta(int numCuenta);
	void mostrarCuentas();
};

