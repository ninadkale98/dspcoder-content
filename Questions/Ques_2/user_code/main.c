#include <stdio.h>
#include "util/util.h"

#define ARR_SIZE 200
#define FILTER_TAP_NUM 25

double filter_coeffs[FILTER_TAP_NUM] = {
    0.008343267095683986,
    0.007149583224306677,
    0.0014492517668356205,
    -0.01331060569409418,
    -0.0345042249128654,
    -0.053675798671946655,
    -0.05866861647110748,
    -0.03857434732652084,
    0.01033141819616749,
    0.08087666209830395,
    0.15569629640166371,
    0.2128725965553248,
    0.23427451265344562,
    0.2128725965553248,
    0.15569629640166371,
    0.08087666209830395,
    0.01033141819616749,
    -0.03857434732652084,
    -0.05866861647110748,
    -0.053675798671946655,
    -0.0345042249128654,
    -0.01331060569409418,
    0.0014492517668356205,
    0.007149583224306677,
    0.008343267095683986
};


int main(){
    printf("\t -- FIR Filter Code -- \n"); 

    // --------------------------------------------------
    //            Generate Noisy Data
    
    // Seed the random number generator
    srand(time(NULL));  

    double xs[ARR_SIZE];
    double ys[ARR_SIZE];
    double dummy; 

    for (int i = 0; i < ARR_SIZE; i++) {
        xs[i] = i;
        ys[i] = noisy_sine_wave(xs[i]);
    }

    
    // Initial Plot
    plot_XY(xs, ys, sizeof(xs)/sizeof(xs[0]), "noisy_plot.png");
    // --------------------------------------------------

    for(int i = ARR_SIZE -1 ; i > 0 ; i--){
        dummy = 0.0;

        for(int j = 0 ; j < FILTER_TAP_NUM ; j++){

            if( (i-j) >= 0){
                dummy += ys[i - j] * filter_coeffs[j]; 
            }
        }
        ys[i] = dummy; 
    }
    
    // New Plot
    plot_XY(xs, ys, sizeof(xs)/sizeof(xs[0]), "filter_plot.png");

}

// backend 
// complete this code(function)