#include <stdio.h> 
 
int main() { 
    int a, b, c, largest; 
     
    printf("Enter three numbers: "); 
    scanf("%d %d %d", &a, &b, &c); 
     
    // if (a >= b){
    //     if (a >= c){
    //         printf("A is largest %d", a);
    //     }
    //     else { 
    //         printf("C is largest %d", c);
    //     }
    // }
    // else if(b >= c){
    //     printf("B is largest %d", b);
    // }
    // else printf("C is largest %d", c);

    // // Method 1: Using if-else 
    // if(a >= b && a >= c) { 
    //     largest = a; 
    //     printf("Largest number (if-else): a = %d\n", largest); 
    // } else if(b >= a && b >= c) { 
    //     largest = b;
    //     printf("Largest number (if-else): b = %d\n", largest);  
    // } else { 
    //     largest = c;
    //     printf("Largest number (if-else):c = %d\n", largest);  
    // } 
    // printf("Largest number (if-else): %d\n", largest); 
     
    // Method 2: Using conditional operator 
    largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c); 
    printf("Largest number (ternary): %d\n", largest); 
     
    return 0; 
} 