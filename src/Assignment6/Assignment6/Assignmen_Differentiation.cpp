/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [LEE CHANG HYEON]
Created          : 26-03-2018
Modified         : 13-05-2021
Language/ver     : C++ in MSVS2019

Description      : Assginmen_differentiation.cpp
-------------------------------------------------------------------------------*/

#define Assignment	6		// enter your assignment number
#define eval		0		// set 0

#include "../../../include/myNM.h"

int main(int argc, char* argv[])
{
	/*	 [※ DO NOT EDIT IT !!!]   Resources file path setting for evaluation	*/
	std::string path = "C:/NM_data_2021/Assignment" + std::to_string(Assignment) + "/";
	
#if eval
	path += "eval/";
#endif

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified file name						*/
	/*	   : For each assignment, the file name will be notified on HISNET		*/
	/*==========================================================================*/
	int m = 21;
	double x[] = { 0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.2,3.4,3.6,3.8,4.0 };
	double y[] = { -5.87,-4.23,-2.55,-0.89,0.67,2.09,3.31,4.31,5.06,5.55,5.78,5.77,5.52,5.08,4.46,3.72,2.88,2.00,1.10,0.23,-0.59 };
	double dYdX[21];
	double dYdX2[21];
	Matrix t = arr2Mat(x, m, 1);
	Matrix pos = arr2Mat(y, m, 1);

	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	
	// Using gradient function
	printf("\n******************************************************************");
	printf("\n|                     Using gradient function                    |");
	printf("\n******************************************************************\n");
	Matrix vel = gradient(t, pos);
	Matrix acc = gradient(t, vel);
	

	printMat(t, "t");
	printMat(pos, "x");
	printMat(vel, "vel");
	printMat(acc, "acc");



	// Using gradeint1D function
	printf("\n********************************************************************");
	printf("\n|                     Using gradient1d function                    |");
	printf("\n********************************************************************\n");

	gradient1D(x, y, dYdX, m);
	Matrix vel1d = arr2Mat(dYdX, m, 1);
	gradient1D(x, dYdX, dYdX2, m);
	Matrix acc1d = arr2Mat(dYdX2, m, 1);

	printMat(t, "t");
	printMat(pos, "x");
	printMat(vel1d, "vel using 1d array");
	printMat(acc1d, "acc using 1d array");


	// Using gradientFunc function
	printf("\n**********************************************************************");
	printf("\n|                     Using gradientFunc function                    |");
	printf("\n**********************************************************************\n");

	//Matrix xin = txt2Mat(path, "Q2_vecxin");
	Matrix dydx = gradientFunc(myFunc, t);

	printMat(t, "xin");
	printMat(dydx, "dydx");


	// Modified newtonRaphson function using input argument as function
	printf("\n**************************************************************************");
	printf("\n|                     Modified newtonRaphson function                    |");
	printf("\n**************************************************************************\n");

	double x0 = 1;
	double tol = 1.0e-9;
	newtonRaphsonFunc(myFunc, mydFunc, x0, tol);


	system("pause");
	return 0;
}

// 라이브러리는 보존시키고 함수만 바꾸는 코드 짜보자
	// Define a function that defines the target equation.
	double myFunc(const double x) {
	return  x * x * x;
}

	// Define a derivative function that defines the target equation.
	double mydFunc(const double x) {
		return  3 * x * x;
	}