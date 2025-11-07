import java.util.*;
import java.util.Arrays;

public class Multi_Dimennsional_Array {
    public static void main(String[] args) {
    // 2D Array Example
        int numbers[][] = new int[2][3];
        numbers[0][0] = 10;
        numbers[0][1] = 20;
        numbers[0][2] = 30;
        numbers[1][0] = 40;
        numbers[1][1] = 50;
        numbers[1][2] = 60;
        // Displaying the 2D array elements
        System.out.println("2D Array elements:");
        for (int i = 0; i < numbers.length; i++) {
            for (int j = 0; j < numbers[i].length; j++) {
                System.out.println("Element at index [" + i + "][" + j + "]: " + numbers[i][j]);
            }
        }
        // We can also display the 2D array using a toString method
        System.out.println("2D Array as a string: " + Arrays.deepToString(numbers));

        // We can also initialize a 2D array with values directly
        int numbers2[][] = {
            {10, 20, 30},
            {40, 50, 60}
        };
        // Displaying the 2D array elements 
        System.out.println("2D Array elements :");
        for (int i = 0; i < numbers2.length; i++) {
            for (int j = 0; j < numbers2[i].length; j++) {
                System.out.println("Element at index [" + i + "][" + j + "]: " + numbers2[i][j]);
            }
        }

    // 3D Array Example
        int numbers3[][][] = new int[2][2][2];
        numbers3[0][0][0] = 1;
        numbers3[0][0][1] = 2;
        numbers3[0][1][0] = 3;
        numbers3[0][1][1] = 4;
        numbers3[1][0][0] = 5;
        numbers3[1][0][1] = 6;
        numbers3[1][1][0] = 7;
        numbers3[1][1][1] = 8;
        // Displaying the 3D array elements
        System.out.println("3D Array elements:");
        for (int i = 0; i < numbers3.length; i++) {
            for (int j = 0; j < numbers3[i].length; j++) {
                for (int k = 0; k < numbers3[i][j].length; k++) {
                    System.out.println("Element at index [" + i + "][" + j + "][" + k + "]: " + numbers3[i][j][k]);
                }
            }
        }
        // We can also display the 3D array using a toString method
        System.out.println("3D Array as a string: " + Arrays.deepToString(numbers3));
        // We can also initialize a 3D array with values directly
        int numbers4[][][] = {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        };
        // Displaying the 3D array elements
        System.out.println("3D Array elements:");
        for (int i = 0; i < numbers4.length; i++) {
            for (int j = 0; j < numbers4[i].length; j++) {
                for (int k = 0; k < numbers4[i][j].length; k++) {
                    System.out.println("Element at index [" + i + "][" + j + "][" + k + "]: " + numbers4[i][j][k]);
                }
            }
        }

    }
}