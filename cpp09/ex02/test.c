#include <unistd.h>
#include <stdio.h>

void recursion(int a){
    a++;
    printf(" \na = %d",a);
    if(a <10)
        recursion(a);
    printf(" \na = %d",a);
}




int main(){
    recursion(0);
}