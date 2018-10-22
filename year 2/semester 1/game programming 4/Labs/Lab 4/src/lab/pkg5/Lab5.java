package lab.pkg5;

public class Lab5 {
    private static double points;
    public static void main(String[] args) {
        Circle circle = new Circle(5,3);
        Square square = new Square(2,2);
        
        setPoints(circle);
        setPoints(square);
        
        System.out.println("You got " + points + " points");
        
    }
    public static void setPoints(Shape s) {
        points += s.getArea() * s.getColour();
        
    }
    
}
