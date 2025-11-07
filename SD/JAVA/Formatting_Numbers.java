import java.text.NumberFormat;

public class Formatting_Numbers {
    public static void main(String[] args) {
// Formatting numbers using NumberFormat class
        // Currency formatting
        NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance();
        String US = currencyFormatter.format(12345.678);
        System.out.println("Formatted as currency: " + US);

        // Method chaining
        String chainedFormat = NumberFormat.getCurrencyInstance().format(98765.4321);
        System.out.println("Chained formatting as currency: " + chainedFormat);

        // Percentage formatting
        NumberFormat percentFormatter = NumberFormat.getPercentInstance();
        String percent = percentFormatter.format(0.75);
        System.out.println("Formatted as percentage: " + percent);

        // Integer formatting
        NumberFormat integerFormatter = NumberFormat.getIntegerInstance();
        String integer = integerFormatter.format(12345.678);
        System.out.println("Formatted as integer: " + integer);

        // Customizing decimal places
        NumberFormat customFormatter = NumberFormat.getNumberInstance();
        customFormatter.setMinimumFractionDigits(3);
        customFormatter.setMaximumFractionDigits(3);
        String custom = customFormatter.format(12345.6789);
        System.out.println("Custom formatted number (3 decimal places): " + custom);
        
    }
}
