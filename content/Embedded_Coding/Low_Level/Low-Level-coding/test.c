#include <stdio.h>

int check_nth_bit(u_int8_t num , int n){

    int out; 

    out = (num & (1 << (n -1))) >> (n-1); 

    for (int i = 0; i < 8; i++){
        if( (num & (1<< (7 - i))  )){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n"); 

    return out; 

}

int main(){
    u_int8_t num = 0b11011010; 

    if (check_nth_bit(num, 0)){
        printf("bit is set"); 
    }
    else{
        printf("bit is not set"); 
    }


}



// 110110

//

// 0110110 & 0x0 = 0 -> 6

// 110110 + 1001
