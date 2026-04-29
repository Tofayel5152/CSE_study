#include <stdio.h> 
 
int main() { 
    char str[100]; 
    int length = 0; 
     
    printf("Enter a string: "); 
    scanf("%[^\n]", str);
     
    while(str[length] != '\0') { 
        length++; 
    } 
     
    printf("Length of string: %d\n", length); 
     
    return 0; 
} 