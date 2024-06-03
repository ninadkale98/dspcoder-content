#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    *x ^= *y; 
    *y ^= *x; 
    *x ^= *y; 

}

int main(){

    int *num1 = (int *)malloc(sizeof(int)); 
    int *num2 = (int *)malloc(sizeof(int)); 

    *num1 = 1;
    *num2 = 9; 
    printf("%d %d \n", *num1 , *num2);

    swap(num1, num2);

    printf("%d %d", *num1 , *num2);
}