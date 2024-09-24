import java.util.Scanner;

public class EncryptAndDecrypt {
    public static void main(String args[]) {
        String sourceString = "Sieg Heil";
        System.out.println("Enter the password to encrypt: " + sourceString);
        Scanner scanner = new Scanner(System.in);
        String password = scanner.nextLine();
        String secret = encrypt(sourceString, password);
    }

    String encrypt(String sourceString, String password) {
        char [] pArray = password.toCharArray();
        int n = pArray.length;
        char [] sArray = sourceString.toCharArray();
        int m = sArray.length;
        for ( int k = 0; k < m; k++) {
            int decyptedCode = pArray[k] + sArray[k % n];
            sArray[k] = (char)decyptedCode;
        }
        return new String(sArray);
    }
}