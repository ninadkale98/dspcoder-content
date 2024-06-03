//Given a function that generates a random integer in the range of [0, MAX), write a function that gets an integer x as input and returns a random integer in [0, x).


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

int square(int x){
    return x*x ; 
}

int give_rand(int x){
    int temp = rand(); 
    int val = temp % x ;  // 0 to randmax
    return val; 
}

bool test_function( int (*func)( int) ){

    assert(  func(0) == 0);
    assert(  func(1) == 1);
    assert(  func(2) == 4);
    assert(  func(3) == 9);
    assert(  func(5) == 25);
    

    return false; 

}

int main(){

    srand(time(NULL));
    int num = 15; 

    test_function(square); 
    
    printf("%d" ,  give_rand(num)); 
    
}