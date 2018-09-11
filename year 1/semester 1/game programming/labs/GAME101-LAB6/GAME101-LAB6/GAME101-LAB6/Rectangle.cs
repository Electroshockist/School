using System;

namespace GAME101_LAB6
{
    //Create a class called Rectangle which inherits from Shape
    class Rectangle : Shape
    {
        //Create private integer variables width and height
        private int width;
        private int height;

        //Create a constructor for Rectangle which initializes all variables inside the class
        public Rectangle(int w, int h, string n, string c) : base(n, c)
        {
            width = w;
            height  = h;
        }
        //Override the functionality of setShapeType and return the appropriate value
        public override string getShapeType()
        {
            return "Rectangle";
        }
        //Override the functionality of area and return the area of an rectangle
        public override double area()
        {
            return (width * height);
        }
        
    }
}
