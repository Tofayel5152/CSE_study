#include <stdio.h> 

int fact(int n){
    if(n <= 1){
        return 1; 
    }
    else {
        return n * fact(n-1);
    }
}

int main() { 
    int num; 
    long long int factorial = 1; 
    
    printf("Enter a number: "); 
    scanf("%d", &num); 
    
    
    // if(num < 0) { 
    //     printf("Factorial not defined for negative numbers\n"); 
    // } else { 
    //     for(int i = num; i >= 1; i--) { // for(int i = 1; i <= num; i++)
    //         factorial *= i; 
    //     } 
    //     printf("Factorial of %d = %llu\n", num, factorial); 
    // } 

    // factorial = fact(num);

    printf("Factorial: %d", fact(num));

    return 0; 
} 

/*
    Recurrence => 
    f(n) = n * f(n-1)
    f(1) = 1. stop!

*/