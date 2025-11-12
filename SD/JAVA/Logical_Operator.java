public class Logical_Operator {
    public static void main(String[] args) {
        int a = 10;
        int b = 20;
        int c = 30;

        // Using logical AND operator
        if (a < b && b < c) {
            System.out.println("Both conditions are true: a < b and b < c"); // True block within the if statement
        }

        // Using logical OR operator
        if (a > b || b < c) {
            System.out.println("At least one condition is true: a > b or b < c"); // True block within the if statement
        }

        // Using logical NOT operator
        if (!(a > b)) {
            System.out.println("Condition is true: a is not greater than b"); // True block within the if statement
        }

        //Comparision operators 
        int x = 15;
        int y = 25;
        if (x <= y) {
            System.out.println("x is less than or equal to y"); // True block within the if statement
        }
        if (x != y) {
            System.out.println("x is not equal to y"); // True block within the if statement
        }
    }
}
