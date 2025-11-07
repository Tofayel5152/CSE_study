

public class Math_Class {
    public static void main(String[] args) {
        // Using Math class methods
        double number = 25.0;

        // Square root
        double sqrtResult = Math.sqrt(number);
        System.out.println("Square root of " + number + " is: " + sqrtResult);

        // Power
        double powerResult = Math.pow(5, 3); // 5 raised to the power of 3
        System.out.println("5 raised to the power of 3 is: " + powerResult);

        // Absolute value
        int negativeNumber = -10;
        int absResult = Math.abs(negativeNumber);
        System.out.println("Absolute value of " + negativeNumber + " is: " + absResult);

        // Rounding
        double decimalNumber = 7.65;
        long roundResult = Math.round(decimalNumber);
        System.out.println(decimalNumber + " rounded is: " + roundResult);

        // Ceiling
        double ceilResult = Math.ceil(decimalNumber);
        System.out.println("Ceiling of " + decimalNumber + " is: " + ceilResult);

        // Floor
        double floorResult = Math.floor(decimalNumber);
        System.out.println("Floor of " + decimalNumber + " is: " + floorResult);

        // Maximum and Minimum
        int a = 15;
        int b = 25;
        int maxResult = Math.max(a, b);
        int minResult = Math.min(a, b);
        System.out.println("Maximum of " + a + " and " + b + " is: " + maxResult);
        System.out.println("Minimum of " + a + " and " + b + " is: " + minResult);

        // Random number between 0.0 and 1.0
        double randomResult = Math.random();
        System.out.println("Random number between 0.0 and 1.0: " + randomResult);

        // Random integer between 0 and 100
        int randomIntResult = (int)(Math.random() * 100);
        System.out.println("Random integer between 0 and 100: " + randomIntResult);

    }
}
