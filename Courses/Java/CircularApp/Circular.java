package CircularApp;

public class Circular {
    Circle bottom;
    double height;
    public Circular(Circle c, double h) {
        bottom = c;
        height = h;
    }
    public double getVolume() {
        return bottom.getArea() * height / 3;
    }
}
