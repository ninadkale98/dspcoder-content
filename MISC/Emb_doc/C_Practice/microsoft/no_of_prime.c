#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int is_prime(int n){
    if(n == 2){
        return 1; 
    }
    int out = 1;
    for(int i = 2; i < sqrt(n)+1; i++){
        if( n%i == 0){
            out = 0;
            break;
        }

    }
    return out; 
}


int no_of_prime(int n){

    int count = 0; 
    
    for(int j = 2; j < n+1; j++){
        count += is_prime(j);
    }
    
    return count; 

}

int main(){

    int num = 9; 
    
    printf("%d", is_prime(2)); 
}

