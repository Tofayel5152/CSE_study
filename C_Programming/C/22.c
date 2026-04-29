#include <stdio.h> 
#include <ctype.h> 
 
int main() { 
    char str[100]; 
    int length = 0, i, isPalindrome = 1; 
     
    printf("Enter a string: "); 
    scanf("%[^\n]", str); 
     
    // Find length 
    while(str[length] != '\0') { 
        length++; 
    } 
     
    // Check palindrome 
    for(i = 0; i < length / 2; i++) { 
        if(tolower(str[i]) != tolower(str[length - 1 - i])) { 
            isPalindrome = 0; 
            break; 
        } 
    } 
     
    if(isPalindrome) { 
        printf("'%s' is a palindrome\n", str); 
    } else { 
        printf("'%s' is not a palindrome\n", str); 
    } 
     
    return 0; 
} 