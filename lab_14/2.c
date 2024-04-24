#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main()
{
    pid_t p;
    p = fork();
    fork(); 
    if(p < 0) printf("Error"); 
    else if(p == 0) printf("Process id = %d\n", getpid()); 
    else printf("Process created = %d\n", p);

    return 0;
}