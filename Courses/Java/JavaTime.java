import java.time.*;

public class JavaTime {
    public static void main(String args[]) {
        LocalDate dateNow = LocalDate.now();
        LocalDate dateOther = LocalDate.of(1988, 12, 16);
        System.out.println("Local date: " + dateNow);
        System.out.println("Other date: " + dateOther);

        LocalDateTime date = LocalDateTime.now();
        System.out.println("Local date time: " + date);
    }
}
