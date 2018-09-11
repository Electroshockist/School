using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignments
{
    class Vector2D
    {
        private double x;
        private double y;

        //getters and setters
        public double X
        {
            get { return x; }
            set { x = value; }
        }
        public double Y
        {
            get { return y; }
            set { y = value; }
        }


        //Constructor
        public Vector2D(double xValue, double yValue)
        {
            X = xValue;
            Y = yValue;
        }
        //negates x
        public void NegateX()
        {
            X *= -1;
        }
        //negates y
        public void NegateY()
        {
            Y *= -1;
        }
        //adds addendum to corresponding variable
        public void AddVector(double addendumX, double addendumY)
        {
            X += addendumX;
            Y += addendumY;
        }
        //subtracts subtrahend from corresponding variable
        public void SubtractVector(double subtrahendX, double subtrahendY)
        {
            X -= subtrahendX;
            Y -= subtrahendY;
        }
        public void ScalarMultiplication(double scalar)
        {
            X *= scalar;
            Y *= scalar;
        }
        public void ScalarDivision(double scalar)
        {
            X /= scalar;
            Y /= scalar;
        }
        public double GetMagnitude()
        {
            return Math.Sqrt(X*X + Y*Y);
        }
        public double GetAngleInDegrees()
        {
            return Math.Atan2(X, Y) / Math.PI * 180;
        }
        public double GetAngleInRadians()
        {
            return Math.Atan2(X, Y);
        }

        //start of assignment 3
        public void Normalize() {
            //denotes start of assignment 3
            Console.WriteLine("\nStart of assignment 3");
            //gets normals
            var normalX = X / GetMagnitude();
            var normalY = Y / GetMagnitude();
            //prints normals to console
            Console.WriteLine("The normalised vector is: [" + normalX + ", " + normalY + "]");
        }
        public double GetDotProduct(Vector2D otherVector) {
            //generates a new vector called otherVector
            otherVector = new Vector2D( otherVector.X,otherVector.Y);
            //returns dot product
            return (X * otherVector.X + Y * otherVector.Y);
        }
        public double GetAngleBetweenVector(Vector2D otherVector) {
            //directly returns 0 if magnitude is 0, as to not divide by 0
            if (GetMagnitude() == 0 || otherVector.GetMagnitude() == 0)
            {
                return 0;
            }
            else
            {
                //Acos does not like having that long of an argument to parse, so I split it up 
                double mathing = GetDotProduct(otherVector) / (GetMagnitude() * otherVector.GetMagnitude());
                //returns angle
                return ((Math.Acos(mathing)) / (Math.PI)) * 180;
            }
        }
        public void Lerp(Vector2D otherVector, double t) {
             
            double tempx = (1 - t) * X + (t * otherVector.X);
            double tempy = (1 - t) * Y + (t * otherVector.Y);
            Console.WriteLine("The vector [" + X + ", " + Y + "], ["+ otherVector.X + ", " + otherVector.Y + "] lerped by " + t * 100 + "% is: [" + tempx + ", " + tempy + "]");
        }
        public void RotateVector(double angle) {
            double tempx = X * Math.Cos(angle/180*Math.PI) - Y * Math.Sin(angle/180*Math.PI);
            double tempy = X * Math.Sin(angle / 180 * Math.PI) + Y * Math.Cos(angle / 180 * Math.PI);
            Console.WriteLine("The vector [" + x + ", " + y + "] rotated by " + angle + " degrees is: [" + tempx + ", " + tempy + "]");
        }
    }
}
