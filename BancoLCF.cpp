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
	this->cuentas.push_back(cuenta);
}

void BancoLCF::eliminarCuenta(int numCuenta)
{
	for (int i = 0; i < cuentas.size(); i++)
	{
		if (cuentas[i]->getNumeroDeCuenta() == numCuenta)
		{
			cuentas.erase(cuentas.begin() + i);
		}
	}
}

void BancoLCF::mostrarCuentas()
{
	if (this->cuentas.empty())
	{
		cout << "No hay ninguna cuenta" << endl;
	}
	else {
		int contador = 1;
		for (int i = 0; i < this->cuentas.size(); i++) {
			cout << "Helicoptero: " << contador << endl;
			this->cuentas[i]->to_String();
			cout << endl;
			contador++;
		}
	}
}

