#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

void forkMe(){
    printf("Hello World, I am a sweet c program!!");
    fork();
    fork();
}

int main ( ){
    forkMe();
    return 0;
}