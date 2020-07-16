/*
 * Mandelbrot.h
 *
 *  Created on: 14 Jul 2020
 *      Author: freddie
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include <iostream>
#include <complex>

class Matrix
{
public:

	void genMat(int xDim, int yDim);

	int checkMandel(float realComp, float imgComp);

	int mat[1920][1080];

private:

	

	std::complex<double> mandelFunc(std::complex<double> z, std::complex<double> c);

	//int checkMandel(float realComp, float imgComp);

	float interpolate(int* matrix, int xCoord, int yCoord);

	void inpoMat(int* matrix, float* fMatrix,int xDim, int yDim, int fxDim, int fyDim);
};

class Bar
{
public:
	
	float progress;
	float end;
	Bar();

	void add(int increase);

private:

	

};



#endif /* MANDELBROT_H_ */
