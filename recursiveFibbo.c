#include<stdio.h>
int recursiveFibbo(int n){

    if(n==1) return 0;
    if(n==2) return 1;
    return recursiveFibbo(n-1) + recursiveFibbo(n-2);
}

int main(){

    printf("%d",recursiveFibbo(5));

    return 0;
}