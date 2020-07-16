/*
 * Main.cpp
 *
 *  Created on: 14 Jul 2020
 *      Author: freddie
 */
#include "Mandelbrot.h"
#include <iostream>
//#include <opencv2\core.hpp>

int main(void)
{
	Matrix* matrix;
	matrix = new Matrix();
	matrix->genMat(1920, 1080);
	return 0;
}


