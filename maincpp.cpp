//*************************************************************/
//              Written By: Connor Churcott                    / 
//                    Date: July 24, 2024                      /
//                                                             /
// Project: Analysis of Numerical Integration Implementations  /
//                                                             /
//*************************************************************/

//g++ -Wall -Wpedantic -std=c++17 -Wextra -march=haswell -o execpp functionsplus.cpp main.cpp -O3

// Enable clock_gettime: https://stackoverflow.com/a/40515669
#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include "functionsplus.h"

using namespace std; 

const double LOW_BOUND = 0; 
const double HIGH_BOUND = 100000000; 
const int64_t N = 500000000; 

int main(){
    
    double* data = generateDataArray(LOW_BOUND, HIGH_BOUND, N); 

    struct timespec startTrapSIMD, endTrapSIMD; 

    clock_gettime(CLOCK_MONOTONIC, &startTrapSIMD); 
    double resTrapSIMD = myTrapezoidSIMD(data, LOW_BOUND, HIGH_BOUND, N); 
    clock_gettime(CLOCK_MONOTONIC, &endTrapSIMD); 
    double elapsedTimeTrapSIMD = (endTrapSIMD.tv_sec - startTrapSIMD.tv_sec) + (endTrapSIMD.tv_nsec - startTrapSIMD.tv_nsec) / 1e9;
    cout << "myTrapezoidSIMD Result: " << resTrapSIMD << endl; 
    cout << "myTrapezoidSIMD Time: " << elapsedTimeTrapSIMD << endl << endl; 

    free(data);
}