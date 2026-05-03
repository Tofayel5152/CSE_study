#include <stdio.h> 
 
int main() { 
    int n, i, term = 1, diff = 2; 
     
    printf("Enter which term to find: "); 
    scanf("%d", &n); 
     
    for(i = 1; i < n; i++) { 
        term += diff; 
        diff += 2; 
    } 
     
    printf("The %dth term is: %d\n", n, term); 
     


    return 0; 
} 