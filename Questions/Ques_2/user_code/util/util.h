#include "../lib/pbPlots.h"
#include "../lib/supportLib.h"
#include <stdbool.h>


#define AMPLITUDE 1.0
#define FREQUENCY 0.01
#define NOISE_LEVEL 0.2

void plot_XY(void *arr_X, void *arr_Y, int arr_len, char *name);
double noisy_sine_wave(double x);
double sine_wave(double x);
