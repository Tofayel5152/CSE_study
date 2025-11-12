import java.util.Scanner;

public class Read_input {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the console 

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        System.out.println("Hello, " + name + "!");

        System.out.print("Enter your friend's name: ");
        String friendName = scanner.nextLine().trim(); // Using trim() to remove any leading/trailing whitespace
        System.out.println("Your friend's name is " + friendName + ".");

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();
        System.out.println("You are " + age + " years old.");

        scanner.close(); // Closing the scanner to prevent resource leaks
    }
}
