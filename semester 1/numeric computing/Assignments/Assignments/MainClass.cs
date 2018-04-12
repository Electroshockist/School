using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignments
{
    class MainClass
    {
        static void Main(){

            //set x and y
            double x = 3;
            double y = 3;

            //set second vector
            double xtwo = 3;
            double ytwo = 0;

            //2x2 matrix user variable getters
            double e11;
            double e12;
            double e21;
            double e22;

            //second 2x2 matrix values
            double twoe11 = 5;
            double twoe12 = -3;
            double twoe21 = 2;
            double twoe22 = 4;

            //set numbers to add to x and y
            double addX = 1.1;
            double addY = 2.2;

            //set numbers to add to x and y
            double subX = 3.5;
            double subY = 2.1;
            
            //set multiplier
            double multiplier = 4.3;

            //set "lerp by" multiplier
            double lerpby = .25;

            //set angle
            double angle = 45;

            //set rotation angle for rotation matrix
            double rotangle = 45;

            //set matrix scalars
            double scaleX = 2;
            double scaleY = 3;


            //for loop to reset vectors every time
            for (int i = 0; i < 13; i++)
            {
                //implement Vector2D class as myVector
                Vector2D myVector = new Vector2D(x, y);
                Vector2D myVectortwo = new Vector2D(xtwo, ytwo);
                switch (i)
                {
                    case 0:

                        //writes vector to console
                        Console.WriteLine("Vector: " + "[" + x + ", " + y + "]");
                        break;

                    case 1:
                        //negates x and writes vector to console
                        myVector.NegateX();
                        Console.WriteLine("Negative x: " + "[" + myVector.X + ", " + myVector.Y + "]");
                        break;

                    case 2:
                        //negates y and writes vector to console
                        myVector.NegateY();
                        Console.WriteLine("Negative y: " + "[" + myVector.X + ", " + myVector.Y + "]");
                        break;

                    case 3:
                        //adds addX to x and addY to y and writes vector to console
                        myVector.AddVector(addX, addY);
                        Console.WriteLine("Added " + addX + " to x (" + x + ") and " + addY + " to y (" + y + "): " + "[" + myVector.X + ", " + myVector.Y + "]");
                        break;

                    case 4:
                        //subtracts subX from x and subY from y and writes vector to console
                        myVector.SubtractVector(subX, subY);
                        Console.WriteLine("Subtracted " + subX + " from x (" + x + ") and " + subY + " from y (" + y + "): " + "[" + myVector.X + ", " + myVector.Y + "]");
                        break;

                    case 5:
                        //multiand writes vector to console
                        myVector.ScalarMultiplication(multiplier);
                        Console.WriteLine("Multiplied vector [" + x + ", " + y + "] by " + multiplier + ": " + "[" + myVector.X + ", " + myVector.Y + "]");
                        break;

                    case 6:
                        //gets magnitude
                        Console.WriteLine("The magnitude of the vector [" + x + ", " + y + "] " + "is: " + myVector.GetMagnitude());
                        break;

                    case 7:
                        //gets angle in degrees
                        Console.WriteLine("The angle in degrees of the vector [" + x + ", " + y + "] is: " + myVector.GetAngleInDegrees());
                        break;

                    case 8:
                        //normalize
                        myVector.Normalize();
                        break;

                    case 9:
                        //dot product
                        Console.WriteLine("The dot product between vectors [" + x + ", " + y + "] and [" + xtwo + ", " + ytwo + "] is: " + myVector.GetDotProduct(myVectortwo));
                        break;

                    case 10:
                        //angle between vectors
                        Console.WriteLine("The angle between vectors [" + x + ", " + y + "] and [" + xtwo + ", " + ytwo + "] is: " + myVectortwo.GetAngleBetweenVector(myVector));
                        break;

                    case 11:
                        //lerp
                        myVector.Lerp(myVectortwo, lerpby);
                        break;

                    case 12:
                        //rotate
                        myVector.RotateVector(angle);
                        break;
                }
            }
            Console.WriteLine("\nStart of assignment 4");

            //prompts player for input
            Console.WriteLine("Write 4 numbers for a 2x2 matrix:");
            Console.Write("1,1:");
            e11 = Convert.ToInt32(Console.ReadLine());
            Console.Write("1,2:");
            e12 = Convert.ToInt32(Console.ReadLine());
            Console.Write("2,1:");
            e21 = Convert.ToInt32(Console.ReadLine());
            Console.Write("2,2:");
            e22 = Convert.ToInt32(Console.ReadLine());

            //creates matrix
            Matrix2x2 matrix = new Matrix2x2(e11,e12,e21,e22);
            Matrix2x2 otherMatrix = new Matrix2x2(twoe11, twoe12, twoe21, twoe22);
            Matrix2x2 result = matrix.MultiplyMatrix(otherMatrix);
            Vector2D myVectorthree = new Vector2D(xtwo, ytwo);
            Vector2D vectorresult = matrix.MultiplyVector(myVectorthree);
            Console.WriteLine();

            //calls matrix
            Console.WriteLine("Set Matrix");
            matrix.SetMatrix(e11, e12, e21, e22);
            Console.WriteLine();

            //calls identity matrix
            Console.WriteLine("Set Identity Matrix");
            matrix.SetIdentityMatrix();
            Console.WriteLine();

            //calls scaling  matrix
            Console.WriteLine("Set Scaling Matrix");
            matrix.SetScalingMatrix(scaleX, scaleY);
            Console.WriteLine();

            //calls rotation matrix
            Console.WriteLine("Set Rotation Matrix");
            matrix.SetRotationMatrixInDegrees(rotangle);
            Console.WriteLine();

            //calls addmatrix
            Console.WriteLine("Add Matrix");
            matrix.AddMatrix(otherMatrix);
            Console.WriteLine();

            //calls subtractmatrix
            Console.WriteLine("Subtract Matrix");
            matrix.SubtractMatrix(otherMatrix);
            Console.WriteLine();

            Console.WriteLine("\nStart of assignment 5");

            //multiply matricies
            Console.WriteLine("\nMultiplying matricies:\n" + e11 + ", " + e12 + "\n" + e21 + ", " + e22 + "\nand\n" + otherMatrix.E11 + ", " + otherMatrix.E12 + "\n" + otherMatrix.E21 + ", " + otherMatrix.E22 + "\n=");
            Console.WriteLine(result.E11 + ", " + result.E12 + "\n" + result.E21 + ", " + result.E22);
            Console.WriteLine();

            //multiply matrix by vector
            Console.WriteLine("Multiplying matrix:\n" + e11 + ", " + e12 + "\n" + e21 + ", " + e22 + "\nand vector:\n"  + xtwo + "\n" + ytwo + "\n=");
            Console.WriteLine(vectorresult.X + "\n" + vectorresult.Y + "\n");

            //transposes matrix
            Console.WriteLine("Transposing Matrix:");
            matrix.Transpose();
            Console.WriteLine();

            //gets determinant matrix
            Console.WriteLine("Getting Determinant Matrix:");
            Console.WriteLine(matrix.GetDeterminant() + "\n");

            Console.WriteLine("Getting Inverse Matrix:");
            matrix.Inverse();
            Console.WriteLine();
        }
    }
}
