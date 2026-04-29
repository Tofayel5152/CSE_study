#include <stdio.h> 
 
int main() { 
    int marks; 
    char grade; 
     
    printf("Enter marks (0-100): "); 
    scanf("%d", &marks); 
     
    // Method 1: Using if-else 
    printf("\nMethod 1: Using if-else\n"); 
    if(marks >= 90) { 
        grade = 'A'; 
    } else if(marks >= 80) { 
        grade = 'B'; 
    } else if(marks >= 70) { 
        grade = 'C'; 
    } else if(marks >= 60) { 
        grade = 'D'; 
    } else if(marks >= 50) { 
        grade = 'E'; 
    } else { 
        grade = 'F'; 
    } 
    printf("Grade: %c\n", grade); 
     
    // Method 2: Using switch-case 
    printf("\nMethod 2: Using switch-case\n"); 
    switch(marks / 10) { 
        case 10: 
        case 9: 
            printf("Grade: A\n"); 
            break; 
        case 8: 
            printf("Grade: B\n"); 
            break; 
        case 7: 
            printf("Grade: C\n"); 
            break; 
        case 6: 
            printf("Grade: D\n"); 
            break; 
        case 5: 
            printf("Grade: E\n"); 


            break; 
        default: 
            printf("Grade: F\n"); 
    } 
     
    return 0; 
} 