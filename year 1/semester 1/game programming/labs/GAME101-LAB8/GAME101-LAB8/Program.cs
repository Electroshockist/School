using System;

namespace GAME101_LAB8
{
    class Program
    {
        static void Main(string[] args)
        {
            //Declare first matrix
            Matrix a;
            
            //Declare second matrix
            Matrix b;

            //Declare matrix to hold result of matrix operations between first and second matrix
            Matrix result;

            //Declare columns and rows to be supplied by user input
            int cols;
            int rows;

            //Set user input for first matrix rows
            Console.Write("Enter the row dimensions for the first matrix: ");
            rows = Convert.ToInt32(Console.ReadLine());

            //Set user input for first matrix columns
            Console.Write("Enter the column dimensions for the first matrix: ");
            cols = Convert.ToInt32(Console.ReadLine());

            //Instantiate first matrix
            a = new Matrix(rows, cols);

            //Initialize first matrix with user inputted values
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write("Enter matrix one values for row " + (i + 1) + " and column " + (j + 1) + ": ");
                    a.setMatrixEntry(i, j, Convert.ToInt32(Console.ReadLine()));
                }
            }

            //Set user input for second matrix rows
            Console.Write("Enter the row dimensions for the second matrix: ");
            rows = Convert.ToInt32(Console.ReadLine());

            //Set user input for second matrix columns
            Console.Write("Enter the column dimensions for the second matrix: ");
            cols = Convert.ToInt32(Console.ReadLine());

            //Instantiate second matrix
            b = new Matrix(rows, cols);

            //Initialize second matrix with user inputted values
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write("Enter matrix two values for row " + (i + 1) + " and column " + (j + 1) + ": ");
                    b.setMatrixEntry(i, j, Convert.ToInt32(Console.ReadLine()));
                }
            }

            //Print first matrix to Console
            a.print();
            Console.WriteLine();

            //Print second matrix to Console
            b.print();
            Console.WriteLine();

            //Calculate multiplication of first and second matrix 
            result = a * b;

            //If the result of the matrix multiplication is nut null, print matrix to Console
            if (result != null)
                result.print();
            else
                Console.WriteLine("Unable to multiply the matrices suplied.");

            Console.ReadKey();
        }
    }
}
