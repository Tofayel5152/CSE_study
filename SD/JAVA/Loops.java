import java.util.Scanner;

public class Loops {
    public static void main(String[] args) {

        // While Loop executes as long as the condition is true
        int j = 1;
        while (j <= 5) {
            System.out.println("Iteration: " + j);
            j++;
        }
        System.out.println("");

        String input = "";
        Scanner scanner = new Scanner(System.in);
        while (!input.equalsIgnoreCase("exit")) {
            System.out.print("Input: ");
            input = scanner.nextLine().toLowerCase();
            System.out.println("You entered: " + input);
        }
        System.out.println("");

        // Do-While Loop executes at least once before checking the condition
        int k = 1;
        do {
            System.out.println("Iteration: " + k);
            k++;
        } while (k <= 5);
        System.out.println("");

        // For Loop executes a specific number of times
        for (int i = 1; i <= 5; i++) {
            System.out.println("Iteration: " + i);
        }
        System.out.println("");

        // Nested For Loop
        for (int m = 1; m <= 3; m++) {
            System.out.println("-> Outer Loop Iteration: " + m);
            for (int n = 1; n <= 2; n++) {
                System.out.println("  Inner Loop Iteration: " + n);
            }
        }
        System.out.println("");

        // Enhanced For Loop (for-each loop) // Limitation: works only with arrays and collections , not with other data types like int, float, etc. Also, it does not provide access to the index of the current element and cannot be used to modify the elements of the array or collection being iterated over. And it cannot be backward iterate.
        String[] fruits = {"Apple", "Banana", "Cherry", "Date", "Elderberry"};
        for (String fruit : fruits) {
            System.out.println("Fruit: " + fruit);
        }
        System.out.println("");

        // Break and Continue Statements
        for (int p = 1; p <= 10; p++) {
            if (p == 6) {
                System.out.println("Breaking the loop at iteration: " + p);
                break; // Exit the loop when p is 6
            }
            if (p % 2 == 0) {
                System.out.println("Skipping even iteration: " + p);
                continue; // Skip even numbers by going to the next iteration without executing the remaining code
            }
            System.out.println("Odd Iteration: " + p);
        }
    
    }
}
