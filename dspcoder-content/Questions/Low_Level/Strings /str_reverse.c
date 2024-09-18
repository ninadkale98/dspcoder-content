// implement a function which will reverse string 
#include <stdio.h>
#include <stdlib.h>


// a b c d e
// exchange a and f
// len is even : 6 -> 3 exchnages 
// len is odd : 5 -> 3 exchanges

void str_reverse(char* sourcem, int len){
    char temp; 
    
    for(int i = 0 ; i < (len/2) ; i ++ ){
        // str[i]  <-> str[len - 1 - i]
        // len 6 : 0 <-> 5 , 1 <-> 4 2 <-> 3
        temp = * (sourcem + (len - 1 - i)); 
        *(sourcem + (len - 1 - i)) = *(sourcem + i); 
        *(sourcem + i) = temp ; 
    }

}

int main(){

    char string[] = "This is input string"; 

    str_reverse( string , 20 ); 

    printf("%s\n" , string); 

}

// replace char string[] with char* string 
// code wont work as input string is a constant 
// and cannot be changes 



