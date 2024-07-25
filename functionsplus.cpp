//*************************************************************/
//              Written By: Connor Churcott                    / 
//                    Date: July 24, 2024                      /
//                                                             /
//  Project: Analysis of Numerical Integration Implementations /
//                                                             /
//*************************************************************/


#include "./vectorclass/vectorclass.h"
 
using namespace std; 

double function(double x){
    return x*x*x; 
}

//WARNING: CALLS MALLOC, NEEDS TO FREE
double* generateDataArray(double lowBound, double highBound, int64_t n){
    double* data = (double*)malloc((n + 1) * sizeof(double));
    double h = (highBound - lowBound) / n; 

    for(int i = 0; i < n + 1; i++){
        double x = lowBound + i * h;   
        data[i] = function(x); 
    }

    return data; 
}

double myTrapezoidSIMD(double* data, double lowBound, double highBound, int64_t n){

    double h = (highBound - lowBound) / n; 
    double integral = data[0]; 

    Vec4d sum = 0; 
    Vec4d temp;

    for(int i = 0; i < n; i += 4){
        temp.load(data + i);  
        sum += temp; 
    }
    integral += data[n]; 

    integral += 2 * horizontal_add(sum) ; 
    integral *= h / 2; 
    return integral; 
}


