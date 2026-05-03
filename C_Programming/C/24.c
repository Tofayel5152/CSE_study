#include <stdio.h> 
 
int main() { 
    int n, i, term = 3, diff = 1; 
     
    printf("Enter which term to find: "); 
    scanf("%d", &n); 
     
    for(i = 1; i < n; i++) { 
        term += diff; 
        diff++; 
    } 
     
    printf("The %dth term is: %d\n", n, term); 
     
    return 0; 
} 