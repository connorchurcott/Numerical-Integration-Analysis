//*************************************************************/
//              Written By: Connor Churcott                    / 
//                    Date: July 24, 2024                      /
//                                                             /
// Project: Analysis of Numerical Integration Implementations  /
//                                                             /
//*************************************************************/


#include <iostream> 
#include <iomanip>

double function(double x); 

double* generateDataArray(double lowBound, double highBound, int64_t n); 

double myTrapezoidSIMD(double* data, double lowBound, double highBound, int64_t n); 