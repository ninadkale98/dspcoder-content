#include <stdio.h>
#include <stdlib.h>



int main(){

    int num = 15; 
    int out = 0; 

    if ( (num & (num -1))  == 0 ){
        printf("true"); 
    } 
    else{
        printf("false"); 
    }
    
}