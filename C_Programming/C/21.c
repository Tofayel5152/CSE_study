#include <stdio.h> 
 
int main() { 
    char str[100], rev[100]; 
    int length = 0, i; 
     
    printf("Enter a string: ");
    scanf("%[^\n]", str); 
     
    // Find length 
    while(str[length] != '\0') { 
        length++; 
    } 
     
    // Reverse the string 
    for(i = 0; i < length; i++) { 
        rev[i] = str[length - 1 - i]; 
    } 
    rev[length] = '\0'; 
     
    printf("Original string: %s\n", str); 
    printf("Reversed string: %s\n", rev); 


     
    return 0; 
} 