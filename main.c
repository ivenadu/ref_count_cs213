#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void* rc_malloc (int nbytes) {
    int * ref_count = malloc (nbytes + 8);
    *ref_count = 1;
    return ((void*) ref_count) + 8;
}

int* w = NULL;
int* x = NULL;
int* y = NULL;
int* z = NULL;

void foo() {
 int* a = rc_malloc(100);
    x = a;
    y = a;
    z = x;
    w = x;   
}

int main(){
    foo();
    printf("reference count = [%d]\n", *(int*)((void*)y - 8) );
}