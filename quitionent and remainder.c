#include<stdio.h>
int main() {
    int a,quitient,remainder;
    printf("enter a vaue of a");
    scanf("%d",&a);

    quitient=a/2;
    remainder=a%2;
    printf("quitient=%d\n",quitient);
    printf("remainder=%d\n",remainder);
    return 0;
}   