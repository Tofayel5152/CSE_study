#include <stdio.h> 
 
int main() { 
    int a, b, temp; 
     
    printf("Enter two numbers: "); 
    scanf("%d %d", &a, &b); 
     
    printf("Before swapping: a = %d, b = %d\n", a, b); 
     
    // temp = a; 
    // a = b; 
    // b = temp; 
     
    a = a + b; //2 5 => 7 
    b = a - b; // 7 - 5 => 2
    a = a - b; // 7 - 2 => 5

    printf("After swapping: a = %d, b = %d\n", a, b); 
     
    return 0; 
} 