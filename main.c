//*************************************************************/
//              Written By: Connor Churcott                    / 
//                    Date: July 24, 2024                      /
//                                                             /
// Project: Analysis of Numerical Integration Implementations  /
//                                                             /
//*************************************************************/

// gcc -Wall -Wpedantic -Wextra -march=haswell -std=c17 main.c functions.c -o exe -O3

// Enable clock_gettime: https://stackoverflow.com/a/40515669
#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include "functions.h"


#define lowBound 0
#define highBound 100000000 
#define n 500000000


int main() {

    struct timespec startMySimp, endMySimp, startMyTrap, endMyTrap;
    struct timespec startRosSimp, endRosSimp; 
    double* data = generateDataArray(lowBound, highBound, n);

    //Time myTrapezoid
    clock_gettime(CLOCK_MONOTONIC, &startMyTrap); 
    double resultTrap = myTrapezoid(data, lowBound, highBound, n);
    clock_gettime(CLOCK_MONOTONIC, &endMyTrap);
    double elapsedTimeTrap = (endMyTrap.tv_sec - startMyTrap.tv_sec) + (endMyTrap.tv_nsec - startMyTrap.tv_nsec) / 1e9;
    printf("myTrap Results: %lf\n", resultTrap);
    printf("myTrap Time: %.9f seconds\n\n", elapsedTimeTrap);
    


    //Time mySimpsons
    clock_gettime(CLOCK_MONOTONIC, &startMySimp); 
    double resultSimp = mySimpsons(data, lowBound, highBound, n);
    clock_gettime(CLOCK_MONOTONIC, &endMySimp);
    double elapsedTimeSimp = (endMySimp.tv_sec - startMySimp.tv_sec) + (endMySimp.tv_nsec - startMySimp.tv_nsec) / 1e9;
    printf("mySimpsons Results: %lf\n", resultSimp);
    printf("mySimpsons Time: %.9f seconds\n\n", elapsedTimeSimp);

    
    //Time rosettaSimpsons 
    clock_gettime(CLOCK_MONOTONIC, &startRosSimp); 
    double resultRosSimp = rosettaSimpson(data, lowBound, highBound, n); 
    clock_gettime(CLOCK_MONOTONIC, &endRosSimp); 
    double elapsedTimeRosSimp = (endRosSimp.tv_sec - startRosSimp.tv_sec) + (endRosSimp.tv_nsec - startRosSimp.tv_nsec) / 1e9;
    printf("rosSimpsons Results: %lf\n", resultRosSimp);
    printf("rosSimpsons Time: %.9f seconds\n\n", elapsedTimeRosSimp);


    free(data); 
}



