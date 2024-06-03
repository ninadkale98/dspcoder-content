#include <stdio.h>
#include <stdlib.h>


void str_cpy(char * source , char *dest ){

    char * start = dest; 

    while(*source != '\0'){
        *dest = *source ; 
        source += 1; 
        dest += 1; 
    }
    dest = '\0'; 
    dest = start ; 
}


int main(){

    char* string = "This is input string\n"; 
    char* dest = (char *)malloc(21*sizeof(char)); 

    str_cpy( string , dest ); 

    printf("%s" , dest); 

}