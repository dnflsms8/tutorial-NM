/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [LEE CHANG HYEON]
Created          : 26-03-2018
Modified         : 13-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp
----------------------------------------------------------------*/

#include "myNM.h"

void tempFunction(int m);



// Return the dy/dx results for the input data. (truncation error: O(h^2))
Matrix	gradient(Matrix _x, Matrix _y) {
	int m = _x.rows;
	int n = _y.rows;

	if (m != n) {
		printf("data number difference between two vector!\n");
		return createMat(0, 0);
	}

	Matrix Out = createMat(_x.rows, _x.cols);

	// assuming constant h 
	double h = _x.at[1][0] - _x.at[0][0];

	if (m >= 3) {
		// three point forward
		Out.at[0][0] = (-3 * _y.at[0][0] + 4 * _y.at[1][0] - _y.at[2][0]) / (2 * h);


		// two point central difference
		for (int i = 1;i < m - 1;i++) {
			Out.at[i][0] = (_y.at[i + 1][0] - _y.at[i - 1][0]) / (2 * h);
		}

		// three point backward
		Out.at[m - 1][0] = (_y.at[m - 3][0] - 4 * _y.at[m - 2][0] + 3 * _y.at[m - 1][0]) / (2 * h);
	}
	else if (m == 2) {
		// two point forward
		Out.at[0][0] = (_y.at[1][0] - _y.at[0][0]) / h;
		// two point backward
		Out.at[1][0] = (_y.at[1][0] - _y.at[0][0]) / h;
	}

	return Out;
}

// Return the dy/dx results for the input 1d array data. (truncation error: O(h^2))
void gradient1D(double x[], double y[], double dydx[], int m) {

	// assuming constant h 
	double h = x[1] - x[0];

	if (m >= 3) {
		// three point forward
		dydx[0] = (-3 * y[0] + 4 * y[1] - y[2]) / (2 * h);


		// two point central difference
		for (int i = 1;i < m - 1;i++) {
			dydx[i] = (y[i + 1] - y[i - 1]) / (2 * h);
		}

		// three point backward
		dydx[m - 1] = (y[m - 3] - 4 * y[m - 2] + 3 * y[m - 1]) / (2 * h);
	}
	else if (m == 2) {
		// two point forward
		dydx[0] = (y[1] - y[0]) / h;
		// two point backward
		dydx[1] = (y[1] - y[0]) / h;
	}
}


// Return the dy/dx results for the target equation. (truncation error: O(h^2))
Matrix	gradientFunc(double func(const double x), Matrix xin) {

	int n = xin.rows;
	Matrix y = createMat(n, 1);

	// define y[0] to y[n-1]
	for (int i = 0;i < n;i++)
		y.at[i][0] = func(xin.at[i][0]);

	//numerical differentiation
	Matrix df = gradient(xin, y);

	return df;
}

/* NewtonRaphson Method
   _x0      : initial value
   _tol   : tolerance   */
double newtonRaphsonFunc(double func(const double _x0),double dfunc(const double _x0),double _x0, double _tol) {
	int k = 0;
	int kmax = 100;
	double hk;
	double ep; // error

	printf("------------------------------------------------------------------------------------\n");
	printf("         Newton-Raphson Method Result             \n");
	printf("------------------------------------------------------------------------------------\n");
	printf("Newton-Raphson Method Result:\n");

	/*fail-safe program*/
	if (func(_x0) == 0) {
		printf("choose the initial value properly!\n");
		return -1;
	}

	do {
		ep = func(_x0) > 0 ? func(_x0) : -func(_x0);

		printf("Iteration:%d \t", k);
		printf("X(n): %f \t", _x0);
		printf("Tolerance: %.10f\n", ep);

		hk = -(func(_x0)) / (dfunc(_x0));
		_x0 = _x0 + hk;
		k++;

	} while (k<kmax && ep>_tol);

	return _x0;
}

