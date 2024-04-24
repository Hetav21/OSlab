#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

void forkMe(){
    fork();
    fork();
    fork();
    printf("Hello World, I am a sweet c program!!\n");    
}

int main ( ){
    forkMe();
    return 0;
}