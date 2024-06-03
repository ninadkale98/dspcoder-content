#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int *ptr;
} Point;


bool str_end (char* s, char t){
    while (*s != '\0')
    {
        s++; 
    }
    if (*--s == t ){
        return true;
    }
    else{
        return false;
    }
    
}

char *str_cat_old(char* s, char* e){
    char * out = (char *)malloc(sizeof(char)*(strlen(s) + strlen(e) +1)); 
    while (*s != '\0')
    {   
        *out = *s;
        s++; 
        out ++;
    }
    // s is at \0

    while(*e != '\0'){
        *out = *e; 
        e++; 
        out ++; 
    }
    *out = '\0';

    return out;
}

char *str_cat(char* s, char* e){
    char * out = (char *)malloc(sizeof(char)*(strlen(s) + strlen(e) +1)); 
    char * out_start = out; 
    while (*s != '\0')
    {   
        *out = *s;
        s++; 
        out ++;
    }
    // s is at \0

    while(*e != '\0'){
        *out = *e; 
        e++; 
        out ++; 
    }
    *out = '\0';

    return out_start;
}

int main(){

    char *s = "pika";
    char *t = "chu";

    char* out = str_cat(s, t);

}