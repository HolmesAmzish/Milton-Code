/**
 * program: SeekNumber.java
 * date: 2024-09-22
 */

import java.util.Arrays;
import java.util.Scanner;

public class SeekNumber {
    public static void main(String args[]) {
        int start = 0, end, mid;
        int array[] = {12, 45, 67, 89, 123, -45, 67};
        int len = array.length;
        int minIndex = -1;
        for (int i = 0; i < len - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j <= len - 1; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
        System.out.println(Arrays.toString(array));
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an integer, the program will seek the number:");
        int number = scanner.nextInt();
        int count = 0;
        end = len;
        mid = (start + end) / 2;
        while (number != array[mid]) {
            if (number > array[mid])
                start = mid;
            else if (number < array[mid])
                end = mid;
            mid = (start + end) / 2;
            count++;
            if (count > len / 2)
                break;
        }
        if (count > len / 2)
            System.out.printf("%d does not existed in the array.\n", number);
        else
            System.out.printf("%d exists in the array\n", number);
    }
}
