#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int *ptr;
} Point;

typedef struct {
    Point p1;
    Point p2; 
    Point* p3;
} Rectangle;


int main(){
    int a = 13;
    int b = 122; 
    int c = 21; 
    
    Point* pt = (Point*)malloc(sizeof(Point));
    pt->x = 11;
    pt->y = 10;
    pt->ptr = &a; 

    Point p1 = {.x = 1,.y= 1, .ptr = &b};
    Point p2 = {2, 2, &c};

    Rectangle rect = {p1, p2, pt};

    printf( "%d \n", rect.p1.x);
    printf( "%d \n", *rect.p1.ptr); 

    return 0;
}