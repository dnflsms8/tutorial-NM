/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Chang Hyeon LEE
Created          : 14-03-2021
Modified         : 22-03-2021
Language/ver     : C in MSVS2019

Description      : myNM.h
/----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H
#include<stdio.h>
#define L 4
#define E 70
#define I 52.9
#define w0 20


// New function added
void gradient2(double x[]);


extern double newtonRaphson(double _x0, double _tol);
extern double bisectionNL(double _a0, double _b0, double _tol);
extern double hybrid(double _a0, double _b0, double _x0, double _tol);
extern double newtonRaphson2(double _x0, double _tol);
extern double func(double _x);
extern double dfunc(double _x);
extern double ddfunc(double _x);
extern double func2(double _x);
extern double dfunc2(double _x);
#endif