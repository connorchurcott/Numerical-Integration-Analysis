//*************************************************************/
//              Written By: Connor Churcott                    / 
//                    Date: July 24, 2024                      /
//                                                             /
// Project: Analysis of Numerical Integration Implementations  /
//                                                             /
//*************************************************************/


#include "functions.h"
#include <math.h>

double function(double x){
    return x*x*x; 
}

double* generateDataArray(double lowBound, double highBound, int64_t n){
    double* data = (double*)malloc((n + 1) * sizeof(double));
    double h = (highBound - lowBound) / n; 

    for(int i = 0; i < n + 1; i++){
        double x = lowBound + i * h;   
        data[i] = function(x); 
    }

    return data; 
}

double mySimpsons(double* data, double lowBound, double highBound, int64_t n){

    double h = (highBound - lowBound) / n; 
    double integral = data[0] + data[n]; 

    for(int i = 1; i < n; i++){

        if( i % 2 == 1){
            integral += 4 * data[i]; 
        } else {
            integral += 2 * data[i]; 
        }
    }

    integral *= h / 3.0; 
    return integral; 
}

double myTrapezoid(double* data, double lowBound, double highBound, int64_t n){

    double h = (highBound - lowBound) / n; 
    double integral = data[0]; 

    for(int i = 1; i < n; i++){
        integral += 2.0 * data[i]; 
    }
    integral += data[n]; 

    integral *= h / 2.0; 
    return integral; 
}

// Adapted From: https://rosettacode.org/wiki/Numerical_integration#C
double rossetaSimpson(double* data, double from, double to, int64_t n) {
   double h = (to - from) / n;
   double sum1 = 0.0;
   double sum2 = 0.0;
   int i;
   
   for(i = 1; i < n; i += 2)
      sum1 += data[i];

   for(i = 2; i < n; i += 2)
      sum2 += data[i]; 

   double integral = h / 3.0 * (data[0] + data[n] + 4.0 * sum1 + 2.0 * sum2);
   return integral; 

}

double myLRiemann(double* data, double lowBound, double highBound, int64_t n){

    double h = (highBound - lowBound) / n; 
    double integral = 0; 

    for(int i = 0; i < n; i++){
        integral += data[i]; 
    }

    integral *= h; 
    return integral; 
}
