#include "BancoLCF.h"

BancoLCF::BancoLCF(vector<CuentaBancaria*> cuentas)
{
	this->cuentas = cuentas;
}

vector<CuentaBancaria*> BancoLCF::getcuentas()
{
	return cuentas;
}

void BancoLCF::setcuentas(vector<CuentaBancaria*> cuentas)
{
	this->cuentas = cuentas;
}

BancoLCF::~BancoLCF()
{
	for (int i = 0; i < cuentas.size(); i++)
	{
		delete this->cuentas[i];
	}
	this->cuentas.clear();
}

void BancoLCF::agregarCuenta(CuentaBancaria* cuenta)
{
}

void BancoLCF::eliminarCuenta(int numCuenta)
{
}

void BancoLCF::mostrarCuentas()
{
}

