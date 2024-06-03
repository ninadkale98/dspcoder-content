#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RAM, 
    SUNIL, 
    MAHESH
} Name ; 

typedef enum {
    BOOL_TRUE = 15,
    BOOL_FALSE = 0
} BOOL_TYPE;

typedef struct {
    int age; 
    float weight; 
} Child; 

typedef struct {
    int age ; 
    float weight ; 
    Name name ; 
    BOOL_TYPE male ; 
    Child child ; 

} Person ;


typedef struct {
    int a:1 ; 
    int b:1 ; 
    int c:1 ;
    int d:1 ;
} regs;

typedef union Adcreg{
    int all : 4;
    regs bits ; 
} Adcreg ;




int main(void){
    Person person1 = {.age = 10, .weight = 112.0, .name = RAM , .male = BOOL_TRUE , .child.age = 1, .child.weight = 10.0};

    Person *person2 = &person1; 

    // printf("%f", person2->weight); 

    Adcreg adc_reg; 
    adc_reg.all = 4; 

    printf("%d", adc_reg.bits); 

    int *ptr = (int*) malloc( 5*sizeof(int));

}

