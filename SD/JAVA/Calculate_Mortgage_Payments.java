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

        int principal = 0, numberOfPayments = 0;
        float monthlyInterest = 0;

        Scanner scanner = new Scanner(System.in);

        while (true) {
        System.out.print("Principal (1,000 to 1,000,000): ");
        principal = scanner.nextInt();

        if (principal >= 1000 && principal <= 1_000_000)
            break;
        System.out.println("Enter a value between 1,000 and 1,000,000.");
        }

        while (true) {
        System.out.print("Annual Interest Rate (1 to 30): ");
        float annualInterest = scanner.nextFloat();

        if (annualInterest > 0 && annualInterest <= 30){
            monthlyInterest = annualInterest / PERCENT / MONTHS_IN_YEAR;
            break;
        }
        System.out.println("Enter a value greater than 0 and less than or equal to 30.");
        }


        while (true) {
        System.out.print("Period (Years 1 to 30): ");
        byte years = scanner.nextByte();
        
        if (years >= 1 && years <= 30) {
            numberOfPayments = years * MONTHS_IN_YEAR;
            break;
        }
        System.out.println("Enter a value between 1 and 30.");
        }

        double mortgage = principal * (monthlyInterest * Math.pow(1 + monthlyInterest, numberOfPayments))
                / (Math.pow(1 + monthlyInterest, numberOfPayments) - 1);

        String mortgageFormatted = NumberFormat.getCurrencyInstance().format(mortgage);
        System.out.println("Mortgage: " + mortgageFormatted);

    }
}
