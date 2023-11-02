/*
 * Colecta.h
 *
 *  Created on: 01/11/2023
 *      Author: algo2
 */

#ifndef COLECTA_H_
#define COLECTA_H_


#include "Colecta.h"

#include "Vector.h"

class Colecta {

private:
	Vector<Donaciones *> *donaciones;
	double maximaDonacion;
	double montoObjetivo;
	double recaudacion;
public:

	/*
	 * pre:
	 * post:
	 */
	Colecta(double montoObjetivo, double MaximaDonacionIndividual, unsigned int cantidadDeDonaciones){

		this->montoObjetivo = montoObjetivo;
		this->recaudacion = 0.0 ;
		this->maximaDonacion = MaximaDonacionIndividual;

		this->donaciones = new Vector<Donaciones *>(cantidadDeDonaciones);

		for (unsigned int i=1 ; i<=cantidadDeDonaciones ; i++){
			this->donaciones->setDato(i , new Donaciones(i));
		}

	}


	/*
	 * pre:
	 * post:
	 */
	virtual ~Colecta(){

		for(unsigned int i = 0; i < this->donaciones->getLongitud() ; i++)
		{
			if(this->donaciones->getDato(i) != NULL)
			{
				delete this->donaciones->getDato(i);
			}
		}
		// averiguar ([])
		delete [] this->donaciones;
	}




	/*
	 * pre:
	 * post:
	 */
	double getRecaudacion(){
		return this->recaudacion;
	}


	/*
	 * pre:
	 * post:
	 */
	void donar(double monto){
		if (monto > this->maximaDonacion){
			monto = this->maximaDonacion;
		}
		this->recaudacion += monto;
	}

	/*
	 * pre:
	 * post:
	 */
	unsigned int contarDonaciones(){
		return this->donaciones->getLongitud();
	}

	double calcularDonacionMaxima(){

		double maxima = 0.0;

		for (unsigned int i = 1; i <=this->donaciones->getLongitud(); i++){
			if (this->donaciones->getDato(i)->getDonacionIndividual() > maxima){
				maxima = this->donaciones->getDato(i)->getDonacionIndividual();
			}
		}
		return (maxima);
	}

	/*
	 * pre:
	 * post:
	 */
	double calcularRecaudacionFaltante(){


		if (this->recaudacion >= this->montoObjetivo){
			return 0;
		}else{
			return (this->montoObjetivo - this->recaudacion);
		}


	}


	/*
	 * pre:
	 * post:
	 */
	Vector<Donaciones *>* getDonaciones(){
		return this->donaciones;
	}

};






#endif /* COLECTA_H_ */
