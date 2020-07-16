/*
 * Mandelbrot.cpp
 *
 *  Created on: 14 Jul 2020
 *      Author: freddie
 */
#include "Mandelbrot.h"

std::complex<double> Matrix::mandelFunc(std::complex<double> z, std::complex<double> c)
{
	std::complex<double> temp = z*z;
	temp+=c;
	return temp;
}

int Matrix::checkMandel(float realComp, float imgComp)
{
	std::complex<double> c(realComp, imgComp);
	std::complex<double> z(0.0, 0.0);
	for(int i=0; i<81; i++)
	{
		z=mandelFunc(z, c);
	}
	if(real(z)<5 and real(z)>-5 and imag(z)<5 and imag(z)>-5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Matrix::genMat(int xDim, int yDim)
{
	Bar loadingBar;
	loadingBar.end = xDim * yDim;
	float xCoord = -2;
	float yCoord;
	for(int i=0; i<xDim; i++)
	{
		yCoord=-1;
		for(int j=0; j<yDim; j++)
		{
			mat[i][j] = checkMandel(xCoord, yCoord);
			yCoord+=2/yDim;
		}
		xCoord+=2/yDim;
		loadingBar.add(1080);
	}
}

Bar::Bar()
{
	progress = 0;
	end = 1;
}

void Bar::add(int increase)
{
	std::string barGone = "";
	std::string barRemaining = "";
	progress += increase;
	float percentage;
	percentage = progress / end * 100;
	int barProgress = roundf(percentage / 5);
	int remainingBar = 20 - barProgress;
	for (int i = 0; i < barProgress; i++)
	{
		barGone += "#";
	}
	for (int i = 0; i < remainingBar; i++)
	{
		barRemaining += " ";
	}
	std::cout << "\r" << "Generating Values |" << barGone << barRemaining << "| " <<progress << "/" << end << " " << roundf(percentage) << "%";
}
