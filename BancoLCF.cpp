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
	for (int i = 0; i < cuentas.size(); i++) // borrar memoria
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
			cuentas.erase(cuentas.begin() + i); // eliminar la cuenta
		}
	}

}

void BancoLCF::mostrarCuentas()
{
	if (this->cuentas.empty())// validacion
	{
		cout << "No hay ninguna cuenta" << endl;
	}
	else {
		int contador = 1;
		for (int i = 0; i < this->cuentas.size(); i++) {
			cout << "Cuenta: " << contador << endl;
			this->cuentas[i]->to_String(); // mostrar las cuentas
			cout << endl;
			contador++;
		}
	}
}

