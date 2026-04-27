#include <stdio.h> 
 
int main() { 
    int days,months, weeks, remainingDays; 
     
    printf("Enter number of days: "); 
    scanf("%d", &days); 
     
     months = days / 30; 
     remainingDays = days % 30;
     weeks = remainingDays / 7;
     remainingDays = remainingDays % 7; 
     
    printf("%d days = %d months ,%d weeks and %d days\n", days, months, weeks, remainingDays); 
     
    return 0; 
} 