import java.util.*;

public class Arithmetic_Expressions {
    public static void main(String[] args) {
        int Result1 = 10 + 5;
        int Result2 = 10 - 5;
        int Result3 = 10 * 5;
        int Result4 = 10 / 5; // As both operands are integers and result is also stored in an integer it results in an integer value
        double Result5 = 10 / 3; // Division of two integers results in an integer
        double Result6 = 10 / 3.0; // To get a double result,at least one operand must be a double
        // We can also use  type casting to get a double result
        double Result7 = (double)10 / 3; // Here we are converting the integer 10 to a double before division
        int Result8 = 10 % 3; // It gives the remainder after division

        System.out.println("Addition: " + Result1);
        System.out.println("Subtraction: " + Result2);
        System.out.println("Multiplication: " + Result3);
        System.out.println("Division (integer): " + Result4);
        System.out.println("Division (integer result in double): " + Result5);
        System.out.println("Division (double): " + Result6);
        System.out.println("Division (double):" + String.format("%.2f", Result7)); // It limits the numbers after decimal to 2 places
        System.out.println("Modulus: " + Result8);

    // Increment and Decrement operators
        int a = 5;
        int x = a++; // Incrementing by 1 postfix it assigns the current value of a to x, then increments a
        System.out.println("Value of a: " + a);
        System.out.println("After incrementing by 1: " + x);
        int y = ++a; // Incrementing by 1 prefix it increments a first, then assigns the new value to y
        System.out.println("Value of a: " + a);
        System.out.println("After incrementing by 1: " + y);
        int s = a--; // Decrementing by 1 postfix it assigns the current value of a to s, then decrements a
        System.out.println("Value of a: " + a);
        System.out.println("After decrementing by 1: " + s);
        int z = --a; // Decrementing by 1 prefix it decrements a first, then assigns the new value to z
        System.out.println("Value of a: " + a);
        System.out.println("After decrementing by 1: " + z);

    // Augmented assignment operator
        int b = 10;
        b += 5; // Equivalent to b = b + 5
        System.out.println("After += 5: " + b);
        b -= 3; // Equivalent to b = b - 3
        System.out.println("After -= 3: " + b);
        b *= 2; // Equivalent to b = b * 2
        System.out.println("After *= 2: " + b);
        b /= 4; // Equivalent to b = b / 4
        System.out.println("After /= 4: " + b);
        b %= 3; // Equivalent to b = b % 3
        System.out.println("After %= 3: " + b);

    // Order of operations: () -> *,/ -> +,- 
        int result = 10 + 5 * 2; // Multiplication is done first, then addition
        System.out.println("Result without parentheses: " + result);
        result = (10 + 5) * 2; // Parentheses change the order of operations
        System.out.println("Result with parentheses: " + result);

    // Casting
        // Implicit casting
        int intValue = 100;
        double doubleValue = intValue; // int to double
        System.out.println("Implicit casting from int to double: " + doubleValue);
        // Explicit casting
        double anotherDoubleValue = 9.78;
        int anotherIntValue = (int) anotherDoubleValue; // double to int
        System.out.println("Explicit casting from double to int: " + anotherIntValue);
        // Forceful casting
        String strValue = "123";
        int forcedIntValue = Integer.parseInt(strValue); // String to int but the string must represent a valid integer data, else it will throw an error like if we try to convert "abc" to int or "12.34" to int
        System.out.println("Forceful casting from String to int: " + forcedIntValue);

    }
}