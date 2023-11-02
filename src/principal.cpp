/*
 * principal.cpp
 *
 *  Created on: 01/11/2023
 *      Author: algo2
 */

#include "Donaciones.h"
#include "Colecta.h"

#include <iostream>

using namespace std;

int main(){

	Colecta * prueba = new Colecta(500.00, 100.00, 5);


	prueba->getDonaciones()->getDato(1)->setDonacionIndividual(100.00);
	prueba->getDonaciones()->getDato(2)->setDonacionIndividual(100.00);
	prueba->getDonaciones()->getDato(3)->setDonacionIndividual(100.00);
	prueba->getDonaciones()->getDato(4)->setDonacionIndividual(100.00);
	prueba->getDonaciones()->getDato(5)->setDonacionIndividual(100.00);

	for (unsigned int i= 1; i <=5  ; i++){
		prueba->donar(prueba->getDonaciones()->getDato(i)->getDonacionIndividual());
	}

	cout << "Contar Donaciones: " << prueba->contarDonaciones() << endl;

	cout << "Recaudacion: " << prueba->getRecaudacion() << endl;

	cout << "Recaudacion Faltante: " << prueba->calcularRecaudacionFaltante() << endl;

	cout << "Donacion Maxima: " << prueba->calcularDonacionMaxima() << endl;


	return 0;
}
