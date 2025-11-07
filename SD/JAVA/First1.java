import java.util.*; // Importing all classes from java.util package
import java.awt.*; // Importing all classes from java.awt package

public class First1 {
    public static void main(String[] args) {

// Printing to console
        System.out.println("Hello, World!"); // sout + tab shortcut to type System.out.println

// Variable declaration and initialization
        int a = 5;
        int b = 10;
        int s = a + b;
        int sum = s;
        System.out.println("Sum: " + sum);

/* Variable 2 type
 * 1. Primitive Data Types: byte, short, int, long, float, double, char, boolean
 * 2. Non-Primitive(Reference) Data Types: String, Arrays, Classes, Interfaces
 * 
 * Byte: 1 byte range: -128 to 127
 * Short: 2 bytes range: -32,768 to 32,767
 * Int: 4 bytes range: -2,147,483,648 to 2,147,483,647
 * Long: 8 bytes range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
 * Float: 4 bytes range: 1.4E-45 to 3.4028235E38
 * Double: 8 bytes range: 4.9E-324 to 1.7976931348623157E308
 * Char: 2 bytes range: '\u0000' to '\uffff'
 * Boolean: 1 bit values: true or false
 * String: sequence of characters
 * Arrays: collection of similar data types
 * Classes: blueprint for objects
 * Interfaces: abstract type used to specify a behavior that classes must implement
 * 
 * Difference between Primitive and Non-Primitive Data Types:
 * 1. Primitive data types are predefined by the language, while non-primitive data types are created by the programmer.
 * 2. Primitive data types store simple values, while non-primitive data types can store complex data structures.
 * 3. Primitive data types have a fixed size, while non-primitive data types can vary in size.
 * 4. Primitive data types are stored in stack memory, while non-primitive data types are stored in heap memory.
 * 5. Primitive data types do not have methods, while non-primitive data types can have methods.
 * 6. Primitive data types are faster to access, while non-primitive data types may require additional processing.
 * 7. Primitive data types are passed by value, while non-primitive data types are passed by reference.

 */
// Declaring and initializing variables of different data types
        byte byteVar = 127;
        short shortVar = 32_767;
        int intVar = 2_147_483_647;
        long longVar = 9_223_372_036_854_775_807L; // 'L' suffix for long literals
        float floatVar = 3.4028235E38F; // 'F' suffix for float literals
        double doubleVar = 1.7976931348623157E308;
        char charVar = 'A';
        boolean booleanVar = true;
        String stringVar = "Hello, Java!";
        int ArrayVar[] = {1, 2, 3, 4, 5};

        System.out.println("Array Size: " + ArrayVar.length);// .length to get size of array its a property not method
        String upperCaseString = stringVar.toUpperCase(); // toUpperCase() is a method of the String class
        System.out.println("Uppercase String: " + upperCaseString);

        // Reference data types can be declared as new objects

        Date now = new Date(); // Date is a class in java.util package
        //System.out.println("now's time & date: " + now.toString()); // toString() is a method of the Date class
        System.out.println("now's time & date: " + now); // toString() is called implicitly when printing an object

        Point point1 = new Point(1,2); // Point is a class in java.awt package
        Point point2 = point1; // point2 is a reference to the same object as point1
        System.out.println("Point coordinates: (" + point1 + ")"); // x and y are properties of the Point class
        point1.x = 10; // Changing the x coordinate of point1
        System.out.println("Updated Point coordinates: (" + point2 + ")"); // point2 reflects the change because it references the same object 

        // Example of String methods
        String str = "Java Programming";
        System.out.println("String Length: " + str.length()); // length() method returns the length of the string
        System.out.println("Substring: " + str.substring(5, 16)); // substring method returns a part of the string
        System.out.println("Index of 'P': " + str.indexOf('P')); // indexOf method returns the index of the first occurrence of a character
        System.out.println("Contains 'Java': " + str.contains("Java")); // contains method returns true if the string contains the specified sequence of characters     
        System.out.println("Replace 'Java' with 'Python': " + str.replace("Java", "Python")); // replace method replaces a substring with another substring
        System.out.println("Split by space: " + Arrays.toString(str.split(" "))); // split method splits the string by a delimiter and returns an array
        System.out.println("Trimmed String: '" + str.trim() + "'"); // trim method removes leading and trailing whitespace 
        System.out.println("String to Lowercase: " + str.toLowerCase()); // toLowerCase method converts the string to lowercase 
        System.out.println("String to Uppercase: " + str.toUpperCase()); // toUpperCase method converts the string to uppercase 
        System.out.println("String starts with 'Java': " + str.startsWith("Java")); // startsWith method checks if the string starts with a specified prefix
        System.out.println("String ends with 'ming': " + str.endsWith("ming")); // endsWith method checks if the string ends with a specified suffix
        System.out.println("String equals 'Java Programming': " + str.equals("Java Programming")); // equals method checks if the string is equal to another string
        System.out.println("String equalsIgnoreCase 'java programming': " + str.equalsIgnoreCase("java programming")); // equalsIgnoreCase method checks if the string is equal to another string, ignoring case
        System.out.println("String hashCode: " + str.hashCode()); // hashCode method returns the hash code of the string
        System.out.println("String isEmpty: " + str.isEmpty()); // isEmpty method checks if the string is empty
        System.out.println("String valueOf 123: " + String.valueOf(123)); // valueOf method converts a primitive type to a string
        System.out.println("String format: " + String.format("Hello, %s!", "World")); // format method formats the string using a format specifier
        System.out.println("String compareTo 'Java Programming': " + str.compareTo("Java Programming")); // compareTo method compares two strings lexicographically
        System.out.println("String compareToIgnoreCase 'java programming': " + str.compareToIgnoreCase("java programming")); // compareToIgnoreCase method compares two strings lexicographically, ignoring case
        System.out.println("String toCharArray: " + Arrays.toString(str.toCharArray())); // toCharArray method converts the string to a character array
        System.out.println("String join: " + String.join(", ", "Java", "Programming")); // join method joins multiple strings with a delimiter 

        System.out.println("Hello \"java\" World!"); // Escape double quotes in a string using backslash it is a special character in Java that allows you to include double couts in strings
        System.out.println("Hello 'java' World!"); // Single quotes do not need escaping in Java strings
        System.out.println("Hello \\java\\ World!"); // Escape backslash in a string using double backslash it is a special character in Java that allows you to include a single backslashes in strings
        System.out.println("Hello \njava\nWorld!"); // Escape newline in a string using \n it is a special character in Java that allows you to include new lines in strings
        System.out.println("Hello \tjava\tWorld!"); // Escape tab in a string using \t it is a special character in Java that allows you to include tabs in strings

        // Constants
        final float PI = 3.1416F; // final declares the PI as a constant and it cannot be changed
        System.out.println("Value of PI: " + PI);
    }
}
