package lab.pkg5;

public class Square implements Shape{
    
    double length;
    int colour;
    public Square(double l, int c){
        length = l;
        colour = c;
    }    
    
    @Override
    public int getColour(){
        return colour;
    }
    
    @Override
    public double getArea(){
        return Math.pow(length, 2.0);
    }
    
}
