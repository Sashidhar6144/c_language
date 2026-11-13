#include<stdio.h>
#include<math.h>

int main() {
        int a;
    float area;

    printf("Enter the value of a: ");
    scanf("%d",&a);

    area=(sqrt(3.0)/4.0)*a*a;

    printf("Area of the equilateral triangle is: %.2f",area);
    
    return 0;
}