/*
    * Question: Calculate Mortgage Payments
    * Link: https://www.wikihow.com/Calculate-Mortgage-Payments
    * Description: This Java program calculates the monthly mortgage payments based on the principle, interest rate and number of payments.
    * Mortage = P*{r*(1+r)^n}/[{(1+r)^n}-1]
    * Where,
    * P = Principal loan amount
    * r = Monthly interest rate (annual interest rate divided by 12)
    * n = Number of payments (loan term in years multiplied by 12)
*/

import java.util.*;
import java.text.NumberFormat;

public class Calculate_Mortgage_Payments {
    public static void main(String[] args) {
        
        final byte MONTHS_IN_YEAR = 12;
        final byte PERCENT = 100;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Principal: ");
        int principal = scanner.nextInt();

        System.out.print("Annual Interest Rate: ");
        float annualInterest = scanner.nextFloat();
        float monthlyInterest = annualInterest / PERCENT / MONTHS_IN_YEAR;

        System.out.print("Period (Years): ");
        byte years = scanner.nextByte();
        int numberOfPayments = years * MONTHS_IN_YEAR;

        double mortgage = principal * (monthlyInterest * Math.pow(1 + monthlyInterest, numberOfPayments))
                / (Math.pow(1 + monthlyInterest, numberOfPayments) - 1);

        String mortgageFormatted = NumberFormat.getCurrencyInstance().format(mortgage);
        System.out.println("Mortgage: " + mortgageFormatted);

    }
}
