#include <stdlib.h>
#include <stdio.h>

void func2(){
    int *ptr = NULL; 
    *ptr = 10; 
}



void func1(){
    printf("func1 executed"); 
    func2(); 

}

int main(){

    printf("Hello World"); 
    func1(); 

}

/*

Solution : Sementation fault in func2. As memory is not assigned to pointer, it is pointing to NULL i.e. 0x0. 
Code tried to assign value to this uninitialised position. hence segmentation faul
*/