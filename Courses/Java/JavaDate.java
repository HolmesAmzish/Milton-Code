import java.util.Date;
import java.util.Arrays;

public class JavaDate {
    public static void main(String args[]) {
        Date date = new Date();
        System.out.println("Local time: " + date);
        int a[] = {12,34,-34,2,100};
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
