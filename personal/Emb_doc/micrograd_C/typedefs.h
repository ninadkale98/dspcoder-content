#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV, 
    NA


} Ops; 


typedef struct Value
{
    float data; 
    float grad; 
    Ops operation; 
    struct Value* childrens[2]; 

} Value;



#endif