#include "math_util.h"
#include "typedefs.h"

Value _add(Value *a , Value *b){
    Value out; init(&out);
    out.data = a->data + b->data; 
    out.operation = ADD;

    return out;
}

Value _sub(Value *a , Value *b){
    Value out; init(&out);
    out.data = a->data - b->data; 
    out.operation = SUB;

    return out;
}

Value _mul(Value *a , Value *b){
    Value out; init(&out);
    out.data = a->data * b->data; 
    out.operation = MUL;

    return out;
}

Value _div(Value *a , Value *b){
    Value out; init(&out);
    out.data = a->data / b->data; 
    out.operation = DIV;

    return out;
}