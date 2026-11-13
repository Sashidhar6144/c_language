#include<stdio.h>
#include<math.h>
int main()
{
    int eng, math, sci;
    float avg;
    printf("Enter marks of English, Math and Science: ");
    scanf("%d %d %d", &eng, &math, &sci);

    avg=(eng + math + sci) / 3.0;
    printf("Average marks: %.2f\n", avg);
    return 0;
}