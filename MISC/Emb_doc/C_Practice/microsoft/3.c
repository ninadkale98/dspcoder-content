#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void change_xth_bit(u_int16_t *num , int x, bool val){
    if(val){ // set bit   or with 0001000
        *num |= (1<< (x- 1)); 

    }
    else{ // clear bit   and 11110111  -> ~(00001000)
        *num &= ~(1<<(x-1)); 

    }
}

int total_bits(u_int16_t num ){
    int count = 0; 
    while(num > 0){
        num = (num >> 1); 
        count += 1; 
    }
    return count; 
}


void change_xth_bit_bi(u_int16_t *num , int x, bool val){
    int len = total_bits(*num);
    printf("len is %d\n" , len); 
    if(val){ // set bit   or with 0001000
        *num |= (1<< (len - x)); 

    }
    else{ // clear bit   and 11110111  -> ~(00001000)
        *num &= ~(1<<(len - x)); 

    }
}


int main(){

    u_int16_t num = 255;
    
    change_xth_bit_bi(&num, 6, false); 

    printf("%d", num); 

}