import java.util.*;
import java.util.Arrays;

public class Array {
    public static void main(String[] args) {
        int numbers[] = new int[5];
        numbers[0] = 70;
        numbers[1] = 20;
        numbers[2] = 50;
        numbers[3] = 40;
        numbers[4] = 90;
        // Displaying the array elements
        System.out.println("Array elements:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.println("Element at index " + i + ": " + numbers[i]);
        }
        // We can also display the array using a toString method
        System.out.println("Array as a string: " + Arrays.toString(numbers));
        // Demonstrating the use of an enhanced for loop
        System.out.println("Using enhanced for loop:");
        for (int number : numbers) {
            System.out.println("Element: " + number);
        }
        // Using sort method to sort the array
        java.util.Arrays.sort(numbers);
        System.out.println("Sorted array: " + Arrays.toString(numbers));
    }
}
