public class Ternary_Operator {
    public static void main(String[] args) {
        int number = 10;


        // Using Ternary Operator to check if the number is even or odd
        String result = (number % 2 == 0) ? (number + " is an even number.") : (number + " is an odd number."); // is number devisible by 2 if yes then even else odd
        System.out.println(result);

    }
}
