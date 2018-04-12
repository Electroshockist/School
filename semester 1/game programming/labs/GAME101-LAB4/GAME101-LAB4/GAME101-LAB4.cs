using System;

namespace GAME101_LAB4
{
    class Program
    {
        static void Main(string[] args)
        {
            Matrix matrix;
            int cols, rows = 0;

            Console.Write("Enter the column dimensions for the matrix: ");
            cols = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter the row dimensions for the matrix: ");
            rows = Convert.ToInt32(Console.ReadLine());

            matrix = new Matrix(cols, rows);
          
            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    Console.Write("Enter the matrix value for column " + (i + 1) + " and row " + (j + 1) + ": ");
                    matrix.setMatrixEntry(i, j, Convert.ToInt32(Console.ReadLine()));
                }
            }

            if (matrix.isIdentityMatrix())
            {
                Console.WriteLine("The matrix is an identity matrix.");
            }
            else
            {
                Console.WriteLine("The matrix is not an identity matrix.");
            }

            Console.ReadKey();
        }
    }
}
