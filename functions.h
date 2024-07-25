//*************************************************************/
//              Written By: Connor Churcott                    / 
//                    Date: July 24, 2024                      /
//                                                             /
// Project: Analysis of Numerical Integration Implementations  /
//                                                             /
//*************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

double function(double x); 

//WARNING: CALLS MALLOC, NEEDS TO FREE
double* generateDataArray(double lowBound, double highBound, int64_t n); 

double mySimpsons(double* data, double lowBound, double highBound, int64_t n); 

double myTrapezoid(double* data, double lowBound, double highBound, int64_t n); 

//Adapted From: https://rosettacode.org/wiki/Numerical_integration#C
double rosettaSimpson(double* data, double from, double to, int64_t n); 





