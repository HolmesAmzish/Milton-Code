package CircularApp;

public class View {
    public static void main(String args[]) {
        Circle circle = new Circle(10);
        Circular circular = new Circular(circle, 20);
        System.out.println("The volume of circular: " + circular.getVolume());
    }
}
