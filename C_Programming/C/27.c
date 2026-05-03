#include <stdio.h> 
 
int main() { 
    char str1[100], str2[100]; 
    int i = 0, result; 
     
    printf("Enter first string: "); 
    scanf("%[^\n]", str1); 
    getchar(); // Clear buffer 
    printf("Enter second string: "); 
    scanf("%[^\n]", str2); 
     
    // Manual comparison 
    while(str1[i] != '\0' && str2[i] != '\0') { 
        if(str1[i] != str2[i]) { 
            break; 
        } 
        i++; 
    } 
     
    result = str1[i] - str2[i]; 
     
    if(result > 0) { 
        printf("'%s' is greater than '%s'\n", str1, str2); 


    } else if(result < 0) { 
        printf("'%s' is less than '%s'\n", str1, str2); 
    } else { 
        printf("Both strings are equal\n"); 
    } 
     
    return 0; 
} 