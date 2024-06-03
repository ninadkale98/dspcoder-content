#include "util.h"


void plot_XY(void *arr_X, void *arr_Y, int arr_len, char *name){
    double *X = (double *)arr_X; 
    double *Y = (double *)arr_Y; 

	StartArenaAllocator();
	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	StringReference *errorMessage = CreateStringReference(L"", 0);

    bool success = DrawScatterPlot(canvasReference, 1200, 800, X, arr_len, Y, arr_len, errorMessage);

    if(success){
		size_t length;
		ByteArray *pngdata = ConvertToPNG(canvasReference->image);
		WriteToFile(pngdata, name);
		DeleteImage(canvasReference->image);
		printf("\t -- Plot Completed -- \n");
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	FreeAllocations();

}

double noisy_sine_wave(double x) {
    double noise = ((double)rand() / RAND_MAX) * NOISE_LEVEL - (NOISE_LEVEL / 2.0); 
    return AMPLITUDE * sin(2.0 * M_PI * FREQUENCY * x) + noise;
}

double sine_wave(double x) {
    return AMPLITUDE * sin(2.0 * M_PI * FREQUENCY * x);
}

