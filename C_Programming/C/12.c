#include <stdio.h> 
 
int main() { 
    int num; 
     
    printf("Enter a number: "); 
    scanf("%d", &num); 
     
    // Method 1: Using if-else 
    if(num % 2 == 0) { 
        printf("%d is Even (if-else)\n", num); 
    } else { 
        printf("%d is Odd (if-else)\n", num); 
    } 
     
    // Method 2: Using conditional operator 
    printf("%d is %s (ternary)\n", num, (num % 2 == 0) ? "Even" : "Odd"); 
     
    return 0; 
} 