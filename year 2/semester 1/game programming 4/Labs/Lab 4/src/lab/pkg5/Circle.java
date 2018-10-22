package lab.pkg5;

public class Circle implements Shape{ 
    double radius;
    int colour;
    
    public Circle(double r, int c){
        radius = r;
        colour = c;
    }    
    
    @Override
    public int getColour(){
        return colour;
    }
    
    @Override
    public double getArea(){
        return Math.PI * Math.pow(radius, 2);
    }
}
