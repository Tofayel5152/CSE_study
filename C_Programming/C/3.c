/*
    Bitwise Operator:(Bit by Bit) It does bitwise manipulation.
    
    -> &, |, ~, <<, >>, ^
    
    ^ => XOR (if a and b 's bit are same then a XOR b = 0) 
    A   B   A XOR B    OR =>
    0   0   0               0
    0   1   1               1
    1   0   1               1
    1   1   0               1

    7 ^ 4 =>
    7 -> 0 1 1 1
    4 -> 0 1 0 0
    --------------
   7^4 -> 0 0 1 1 => 3 

*/

#include <stdio.h> 
 
int main() { 
    int a, b; 
     
    printf("Enter two numbers: "); 
    scanf("%d %d", &a, &b); 
     
    printf("Before swapping: a = %d, b = %d\n", a, b); 
     
    a = a ^ b; 
    b = a ^ b; 
    a = a ^ b; 
     
    printf("After swapping: a = %d, b = %d\n", a, b); 
     
    return 0; 
} 