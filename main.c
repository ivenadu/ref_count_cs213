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
    printf("foo() >> enter\n");
    int* a = rc_malloc(100);
    printf("object address pointed by a = [%p]\n", a);
    
    x = a;
    y = a;
    z = x;
    w = x;   
    printf("object address pointed by y = [%p]\n", y);
    printf("foo() << leave \n");

}

int main(){
    foo();
    
    printf("We are now outside of foo()\n\n");
    printf("object address pointed by y = [%p]\n", y);
    printf("reference count = [%d]\n", *(int*)((void*)y - 8));
}