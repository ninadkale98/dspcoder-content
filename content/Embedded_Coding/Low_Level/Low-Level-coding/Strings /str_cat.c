// Concate two strings 
#include <stdio.h>
#include <stdlib.h>

void str_concate(char* str1 , char* str2, char* out , int len1, int len2){

    for(int i = 0 ; i < len1 ; i ++){
        out[i] = str1[i]; 
    }
    for(int i = 0 ; i < len2 + 1 ; i ++){
        out[len1 + i] = str2[i]; 
    }
}

int main(){

    char string_1[] = "This "; 
    char string_2[] = "is input"; 

    char* out; 
    out = malloc((5 + 8) * sizeof(char));

    str_concate( string_1, string_2, out , 5, 8  ); 
    printf("%s\n" , out); 
    free(out); 

}

// question 
// what is issue with following code 
/**
 * char* out; 
 * out = malloc((5 + 8) * sizeof(char));
 * 
 * int main(){
 * 
 *       //some code here
 * 
 * }
 * 
*/