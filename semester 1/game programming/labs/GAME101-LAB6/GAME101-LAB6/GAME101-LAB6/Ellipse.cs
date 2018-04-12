using System;

namespace GAME101_LAB6
{
    //Create a class called Ellipse which inherits from Shape
    class Ellipse : Shape
    {

        //Create private integer variables minor and major
        private int minor;
        private int major;

        //Create a constructor for Ellipse which initializes all variables inside the class
        public Ellipse(int w, int h, string n, string c) : base(n,c)
        {
            minor = w;
            major = h;

        }

        //Override the functionality of setShapeType and return the appropriate value
        public override string getShapeType()
        {
            return "Rectangle";
        }
        //Override the functionality of area and return the area of an ellipse
        public override double area()
        {
            return (Math.PI * minor * major);
        }
    }
}
