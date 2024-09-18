// Implement function which return lenght of string 
#include <stdio.h>
#include <stdlib.h>


int str_len(char* source){
    int len = 0; 
    while(*source != '\0'){
        len += 1; 
        source += 1; 
    }

    return len ; 
}

int main(){

    char* string = "This is input string\n"; 

    int length = 0; 
    
    length = str_len( string  ); 

    printf("Lenght is %d\n" , length); 

}