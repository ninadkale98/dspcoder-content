#include <stdio.h>
#include <stdlib.h>



int main(){

    int *num = (int *)malloc(sizeof(int)); 
    num[0] = 3; 
    printf("%d \n" , sizeof(num));

    
    num = (int *)realloc(num, sizeof(int)*2); 
    num[1] = 4; 
    printf("%d \n" , sizeof(num));
    
    num = (int *)realloc(num, sizeof(int)*3); 
    num[2] = 3;
    printf("%d \n" , sizeof(num));
    
    num = (int *)realloc(num, sizeof(int)*4); 
    num[3] = 30;
    printf("%d \n" , sizeof(num));

    int len = 4;

    
    for(int i = 0 ; i < len; i ++){
        printf("%d ", num[i]); 
    }

    
}
