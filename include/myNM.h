/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [LEE CHANG HYEON]
Created          : 26-03-2018
Modified         : 04-29-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.h
----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include "myMatrix.h"
#include <math.h>

// Return the dy/dx results for the input data. (truncation error: O(h^2))
Matrix	gradient(Matrix _x, Matrix _y);

// Define a function that defines the target equation.
double myFunc(const double x);

// Define a derivative function that defines the target equation.
double mydFunc(const double x);

// Return the dy/dx results for the target equation. (truncation error: O(h^2))
Matrix	gradientFunc(double func(const double x), Matrix xin);

// Return the dy/dx results for the input data. (truncation error: O(h^2))
void gradient1D(double x[], double y[], double dydx[], int m);

//double newtonRaphsonFunc(double func(const double x), double dfunc(const double x), float x0,float tol);
double newtonRaphsonFunc(double func(const double x),double dfunc(const double x),double _x0, double _tol);
#endif