using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignments
{
    class Matrix2x2
    {
        private double e11, e12, e21, e22;

        public double E11
        {
            get { return e11; }
            set { e11 = value; }
        }
        public double E12
        {
            get { return e12; }
            set { e12 = value; }
        }
        public double E21
        {
            get { return e21; }
            set { e21 = value; }
        }
        public double E22
        {
            get { return e22; }
            set { e22 = value; }
        }
        //Default Constructor
        public Matrix2x2() {
            E11 = 0;
            E12 = 0;
            E21 = 0;
            E22 = 0;
        }
        //Constructor
        public Matrix2x2(double newE11, double newE12, double newE21, double newE22) {
            E11 = newE11;
            E12 = newE12;
            E21 = newE21;
            E22 = newE22;
        }
        public void SetMatrix(double newE11, double newE12, double newE21, double newE22) {
            Console.WriteLine(E11 + ", " + E12 + "\n" + E21 + ", " + E22);
        }
        public void SetIdentityMatrix() {
            //sets identity matrix
            double tempE11 = 1;
            double tempE12 = 0;
            double tempE21 = 0;
            double tempE22 = 1;
            //writes identity matrix
            Console.WriteLine("\n" + tempE11 + ", " + tempE12 + "\n" + tempE21 + ", " + tempE22);
        }
        
        public void SetScalingMatrix(double scaleX, double scaleY)
        {
            double tempE11 = scaleX;
            double tempE12 = 0;
            double tempE21 = 0;
            double tempE22 = scaleY;
            //writes identity matrix
            Console.WriteLine("\n" + tempE11 + ", " + tempE12 + "\n" + tempE21 + ", " + tempE22);
        }

        public void SetRotationMatrixInDegrees(double angle) {
            angle = (angle / 180) * Math.PI;
            double tempE11 = Math.Cos(angle);
            double tempE12 = -Math.Sin(angle);
            double tempE21 = Math.Sin(angle);
            double tempE22 = Math.Cos(angle);
            //writes rotation matrix
            Console.WriteLine("\n" + tempE11 + ", " + tempE12 + "\n" + tempE21 + ", " + tempE22);
        }

        //adds matrixes
        public void AddMatrix(Matrix2x2 otherMatrix) {
            double tempE11 = E11 + otherMatrix.E11;
            double tempE12 = E12 + otherMatrix.E12;
            double tempE21 = E21 + otherMatrix.E21;
            double tempE22 = E22 + otherMatrix.E22;

            Console.WriteLine("\n" + tempE11 + ", " + tempE12 + "\n" + tempE21 + ", " + tempE22);
        }

        //subtracts matrixes
        public void SubtractMatrix(Matrix2x2 otherMatrix) {
            double tempE11 = E11 - otherMatrix.E11;
            double tempE12 = E12 - otherMatrix.E12;
            double tempE21 = E21 - otherMatrix.E21;
            double tempE22 = E22 - otherMatrix.E22;

            Console.WriteLine("\n" + tempE11 + ", " + tempE12 + "\n" + tempE21 + ", " + tempE22);
        }

        //assignment5
        public Matrix2x2 MultiplyMatrix(Matrix2x2 otherMatrix) {
            //creates empty vector to hold result
            Matrix2x2 resultMatrix = new Matrix2x2();
            //sets result
            resultMatrix.E11 = E11 * otherMatrix.E11 + E12 * otherMatrix.E21;
            resultMatrix.E12 = E11 * otherMatrix.E12 + E12 * otherMatrix.E22;
            resultMatrix.E21 = E21 * otherMatrix.E11 + E22 * otherMatrix.E21;
            resultMatrix.E22 = E21 * otherMatrix.E12 + E22 * otherMatrix.E22;
            return resultMatrix;
        }
        public Vector2D MultiplyVector(Vector2D otherVector) {
            //creates vector to store result with starting value 0,0
            Vector2D resultVector = new Vector2D(0,0);
            //sets X and Y of result vector
            resultVector.X = E11 * otherVector.X + E12 * otherVector.Y;
            resultVector.Y = E21 * otherVector.X + E22 * otherVector.Y;
            return resultVector;
        }
        public void Transpose() {
            Console.WriteLine("\n" + E11 + ", " + E21 + "\n" + E12 + ", " + E22);
        }
        public double GetDeterminant() {
            return (E11 * E22 - E12 * E21);
        }
        public void Inverse()
        {
            Console.WriteLine("\n" + E22 / GetDeterminant() + ", " + (-1) * E12 / GetDeterminant() + "\n" + (-1) * E21 / GetDeterminant() + ", " + E11 / GetDeterminant());
        }
    }
}
