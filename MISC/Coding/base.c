/*
Question : Given a string check if its Pallindrome or not 




*/

#include <stdbool.h>

bool isPalindrome_pointer(char *s){
    if(*s == '\0'){
        return false;
    }

    char *start = s; 
    while(*(s+1) != '\0'){
        s += 1; 
    }
    char *end = s; 

    while (start < end){
        if(*start != *end){
            return false; 
        }
        start ++; 
        end -- ; 
    }

    return true; 

}

int main(){

    char *s = "Hello-olleH";

    if(isPalindrome_pointer(s)){
        printf("Is pallindrome");
    }
    else{
        printf("Not a pallindrome");
    }

}


// Potential Solutions 

// 1. find total len of string compare forward and backward elements for pallindrome check incrementing forward and decrementing backward indx
// 2. have two pointer pointing to start and end. check if elem pointed by this pointers are same and then ++head, --tail
// 3. 