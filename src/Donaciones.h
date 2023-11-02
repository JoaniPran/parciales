/*
 * Monto.h
 *
 *  Created on: 01/11/2023
 *      Author: algo2
 */

#ifndef DONACIONES_H_
#define DONACIONES_H_

class Donaciones {

private:

	unsigned int numero;
	double MontoDeLadonacion;

public:

	/*
	 * pre:
	 * post:
	 */
	Donaciones(unsigned int numero){
		this->numero = numero;
		this->MontoDeLadonacion = 0.0 ;
	}

	/*
	 * pre:
	 * post:
	 */
	virtual ~Donaciones() { }

	/*
	 * pre:
	 * post:
	 */
	void setDonacionIndividual(double donacion){
		if (donacion < 0){
			throw "estas robando capo";
		}
		this->MontoDeLadonacion = donacion;
	}

	/*
	 * pre:
	 * post:
	 */
	double getDonacionIndividual(){
		return (this->MontoDeLadonacion);
	}

};

#endif /* DONACIONES_H_ */
