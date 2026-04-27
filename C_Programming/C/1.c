#include <stdio.h> 
 
    void sum(int a, int b){
        printf("Sum: %d\n", a + b);
    }

    int sum1(int a, int b){
        return a+b;
    }
int main() { 
    int num1, num2; 
     
    printf("Enter two numbers: "); 
    scanf("%d %d", &num1, &num2); 
    
    sum(num1,num2);

    int sums = sum1(num1,num2);
    printf("%d \n", sums);

    printf("sum: %d \n", sum1(num1,num2));
//     if(num1 > num2){
//         printf("Subtraction: %d\n", num1 - num2); 
//     } 
//    else{
//     printf("Subtraction: %d\n", num2 - num1); 
//    }
//     printf("Multiplication: %d\n", num1 * num2); 
    
//     if(num2 != 0) { 

//         if(num1 > num2){
//         printf("Division: %.2lf\n", (double) num1 / num2); 
//     } 
//     else{
//     printf("Division: %.2lf\n", (double) num2 / num1); 
//     }
//      printf("Division: %.2lf\n", (double) num1 / num2); 
//      printf("Modulus: %d\n", (int)num1 % (int)num2); 
//     } else { 
//         printf("Cannot divide by zero\n"); 
//     } 
    
//     printf("Average: %.2lf\n", (num1 + num2) / 2.0); 
    
    return 0; 
} 