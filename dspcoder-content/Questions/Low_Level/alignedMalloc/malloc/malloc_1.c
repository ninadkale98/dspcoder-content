// In this code char are wrote to outside memory locations as well 
// no warning is raised 
// ask user to find answer of following question 
// 1. will this code compile 
// 2. what will be output of this 
// 3. will free() function free all memory locations 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    unsigned char *p = (unsigned char*)malloc(2*sizeof(unsigned char));
    memset(p,1,60);
    strcpy((char*)p,"abcdefgh"); // **deliberately storing 8bytes**
    
    fprintf(stdout, "Pointer location : %p \t Value: %s\n", p, p);
    free(p); 
    fprintf(stdout, "Pointer location : %p \t Value: %s\n", p, p);
    return 0;
}