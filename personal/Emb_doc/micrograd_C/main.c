#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data Types  ----------------------------------------------------------------

typedef enum {
    ADD,    //0
    MUL,    //1
    TANH,   //2
    NA      //3


} Ops; 


typedef struct Value
{
    float data; 
    float grad; 
    Ops operation; 
    char *label;
    struct Value* childrens[2]; 

} Value;


// Util Functions  ----------------------------------------------------------------

void _init(Value *a){
    a->data = 0.0f; 
    a->grad = 0.0f; 
    a->operation = NA; 
    a->childrens[0] = NULL; 
    a->childrens[1] = NULL; 
    a->label = "";
}

Value _add(Value *a , Value *b){
    Value out; _init(&out);
    out.data = a->data + b->data; 
    out.operation = ADD;
    out.childrens[0] = a; 
    out.childrens[1] = b; 

    return out;
}

Value _mul(Value *a , Value *b){
    Value out; _init(&out);
    out.data = a->data * b->data; 
    out.operation = MUL;
    out.childrens[0] = a; 
    out.childrens[1] = b; 

    return out;
}

Value _tanh(Value *a ){
    Value out; _init(&out);
    out.data = tanh(a->data);
    out.operation = TANH;
    out.childrens[0] = a; 
    
    return out;
}


Value ** build_topo(Value *a, int *total_ops){ // [ [pointer to Value],[pointer to Value],[pointer to Value]..    ]

    // s = list_of_node_to_visit
    int no_of_max_operations = 1000; 
    Value **s = (Value **)malloc(sizeof(Value *)*no_of_max_operations);  
    int curr_indx = 0;

    // add a to s 
    s[curr_indx] = (Value *)malloc(sizeof(Value));
    s[curr_indx] = a; 
    
    for(int i = 0; i < no_of_max_operations; i ++){

        Value *temp = s[i]; 

        if (temp == NULL){
            continue;
        }
        else if(temp->operation == TANH){

            // if(temp->childrens[0]->operation != NA){
            curr_indx += 1; 
            s[curr_indx] = (Value *)malloc(sizeof(Value));
            s[curr_indx] = temp->childrens[0];
            // }
            
        }
        else if (temp->operation == ADD || temp->operation == MUL){
            // append both childrens to s 
            // if(temp->childrens[0]->operation != NA){
            curr_indx += 1; 
            s[curr_indx] = (Value *)malloc(sizeof(Value));
            s[curr_indx] = temp->childrens[0];
            // }
            
            //if(temp->childrens[1]->operation != NA){
            curr_indx += 1; 
            s[curr_indx] = (Value *)malloc(sizeof(Value));
            s[curr_indx] = temp->childrens[1];
            //}
        }
        
        

        if (i > curr_indx+1){
            break; 
        }
    }
    *total_ops = curr_indx + 1; 
    return s; 
    
}

Value **backward (Value *a, int total_inputs ){

    int total_ops; 
    Value **topo = build_topo(a, &total_ops);

    Value **inp_list = (Value **)malloc(sizeof(Value *) * total_inputs);

    for(int i = 0; i < total_inputs; i++){
        inp_list[i] = (Value *)malloc(sizeof(Value));
    }
    int curr_idx = 0; 

    topo[0]->grad = 1.0f;
    for(int i = 0; i < total_ops ; i++){
        if(topo[i]->operation == ADD){
            topo[i]->childrens[0]->grad += 1.0f * topo[i]->grad;
            topo[i]->childrens[1]->grad += 1.0f * topo[i]->grad;

        }
        else if (topo[i]->operation == MUL){
            topo[i]->childrens[0]->grad += topo[i]->childrens[1]->data * topo[i]->grad;
            topo[i]->childrens[1]->grad += topo[i]->childrens[0]->data * topo[i]->grad;

        }
        else if (topo[i]->operation == TANH){
            topo[i]->childrens[0]->grad += (1 - topo[i]->data * topo[i]->data ) * topo[i]->grad;
        }

        else if (topo[i]->operation == NA){
            inp_list[curr_idx] = topo[i];
            curr_idx += 1; 
        }
    }
    
    return inp_list;
}


// Neuron -------------

typedef struct 
{
    float *w; 
    float b; 
} Neuron;

Neuron init_Neuron(int no_of_inputs){
    Neuron out; 
    out.b = (float)rand() / RAND_MAX ; 
    out.w = (float *)malloc(sizeof(float)*no_of_inputs);

    for(int i = 0; i < no_of_inputs ; i++){
        out.w[i] = (float)rand() / RAND_MAX ; 
    }
    return out; 
}

int main(){

    Neuron n = init_Neuron(5); 


    // Inputes
    Value x1, x2;
    _init(&x1); _init(&x2);

    // Weights
    Value w1, w2, b;
    _init(&w1); _init(&w2); _init(&b);

    // Initialise values 
    x1.data = -2.0; x1.label = "x1";
    x2.data = 3.0; x2.label = "x2";
    w1.data = -3.0; w1.label = "w1";
    w2.data = 1.0; w2.label = "w2";
    b.data = 6.881373587019; b.label = "b";


    Value x1w1 = _mul(&x1, &w1); // 1 , 1
    Value x2w2 = _mul(&x2, &w2); // 3.0 , 1
    Value x1w1_x2w2 = _add(&x1w1 , &x2w2); // 4.0 , 0
    Value x1w1_x2w2_b = _add(&x1w1_x2w2, &b ); // 11.0 , 0
    Value out = _tanh(&x1w1_x2w2_b ); // 1.0 , 2

    Value **inps = backward(&out, 5); 

    for(int i = 0; i < 5; i++){  
        printf(" %s Val %f | grad %f \n" ,inps[i]->label, inps[i]->data , inps[i]->grad);
    }

    printf("Done");
    
    return 0;
}




// Inputes
// Value x1, x2;
// _init(&x1); _init(&x2);

// // Weights
// Value w1, w2, b;
// _init(&w1); _init(&w2); _init(&b);

// // Initialise values 
// x1.data = -2.0; 
// x2.data = 3.0; 
// w1.data = -3.0; 
// w2.data = 1.0; 
// b.data = 6.881373587019;


// Value x1w1 = _mul(&x1, &w1); // 1 , 1
// Value x2w2 = _mul(&x2, &w2); // 3.0 , 1

// Value x1w1_x2w2 = _add(&x1w1 , &x2w2); // 4.0 , 0
// Value x1w1_x2w2_b = _add(&x1w1_x2w2, &b ); // 11.0 , 0

// //Value out = _tanh(&x1w1_x2w2_b ); // 1.0 , 2

// //Value out = _add(&x1, &x1);

// Value d = _mul(&x1, &x2); 
// Value e = _add(&x1, &x2); 
// Value f = _mul(&e, &d); 

// backward(&f); 


// printf(" Val %f | grad %f \n" , x1.data , x1.grad);
// printf(" Val %f | grad %f \n" , x2.data , x2.grad);
// // printf(" Val %f | grad %f \n" , w1.data , w1.grad);
// // printf(" Val %f | grad %f \n" , w2.data , w2.grad);
// // printf(" Val %f | grad %f \n" , b.data , b.grad);


// printf("Done");          