#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool is_even(int x){
    if( x & 1){
        return true; 
    }
    else{
        return false; 
    }
}

bool are_same_sign(int x, int y){
    int temp = x ^ y; 

    if(temp > 0){
        return true; 
    }
    else{
        return false;
    }

}


int main(){
    int b = -5;
    int c = -11; 
    int *a = (int *)malloc(sizeof(int)*2);
    a[0] = 1; 
    a[1] = 2; 

    // a = (int *)realloc(a, sizeof(int)*4); 
    a[2] = 3; 
    a[3] = 5; 

    a[4] = 6; 



    
    
    
    


}