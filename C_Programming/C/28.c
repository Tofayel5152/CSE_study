#include <stdio.h> 
 
void trapeziumArea(double a, double b, double h) { 
    printf("Area = %.3lf", ((a + b) / 2) * h); 
} 
 
int main() { 
    double a, b, h, area; 
     
    printf("Enter length of parallel side 1: "); 
    scanf("%lf", &a); 
    printf("Enter length of parallel side 2: "); 
    scanf("%lf", &b); 
    printf("Enter height: "); 
    scanf("%lf", &h); 
     
    trapeziumArea(a, b, h);
    // area = trapeziumArea(a, b, h); 
     
    // printf("Area of trapezium: %.2lf\n", area); 
     
    return 0; 
} 