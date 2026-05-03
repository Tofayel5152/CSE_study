#include <stdio.h> 
#include <math.h> 
 
int isPrime(int num) { 
    int i; 
     
    if(num <= 1) { 
        return 0; 
    } 
     
    for(i = 2; i <= sqrt(num); i++) { 
        if(num % i == 0) { 
            return 0; 
        } 
    } 
     
    return 1; 
} 
 
int main() { 
    int num; 
     
    printf("Enter a number: "); 
    scanf("%d", &num); 
     
    if(isPrime(num)) { 
        printf("%d is a Prime number\n", num); 
    } else { 
        printf("%d is not a Prime number\n", num); 
    } 
     
    return 0; 
} 