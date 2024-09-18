#include <stdio.h>
#include <stdlib.h>

// Write a c functions that takes two bit indices and an int, and reverses the bits in the int between the two indices.

int *reverse_bit(int *, int, int);

int main(){
    int indx1 = 2, indx2 = 5; 
    int *num = (int *)malloc(sizeof(int)); 
    *num = 255; 

    reverse_bit(num, indx2, indx1); 

    printf("%d", *num); 

}

// Assimung bits in little indian 
int *reverse_bit(int *nums, int indx_l, int indx_r){
    for(int i = indx_r; i < indx_l + 1; i++){
        *nums ^= (1 << i); 
    } 
}

