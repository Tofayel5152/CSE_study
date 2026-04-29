#include <stdio.h> 
 
int fib(int n){
    // f(n) = f(n-1) + f(n-2)
    // f(0) = 0 , f(1) = 1
    if(n == 0){
        return 0;
    }
    if( n == 1){
        return 1;
    }
    else{
        return (fib(n-1) + fib(n-2));
    }
}

int main() { 
    int n, i; 
    long long first = 0, second = 1, next; 
     
    printf("Enter number of terms: "); 
    scanf("%d", &n); 
     
    printf("Fibonacci Series: "); 
     
    for(i = n-1; i >= 0; i--) { // i = n , n-1 // for(i = 0; i < n; i++)
        // if(i <= 1) { 
        //     next = i; 
        // } else { 
        //     next = first + second; 
        //     first = second; 
        //     second = next; 
        // } 

        printf("%d ", fib(i)); 

        // printf("%llu ", next); 
    } 
    printf("\n"); 
     
    return 0; 
} 