using System;

namespace GAME101_LAB7
{
    class Matrix
    {
        //Declare a private integer representing the matrix row size
        private int rows;

        //Declare a private integer representing the matrix column size
        private int cols;

        //Declare a private two-dimensional integer matrix
        private int[][] matrix;

        //Matrix Constructor
        //Purpose: Instantiate the matrix array and initialized each entry to 0
        public Matrix(int r = 0, int c = 0)
        {
            //Set the matrix column and row to the parameters supplied
            rows = r;
            cols = c;

            //Instantiate the matrix row
            matrix = new int[rows][];

            //Create a for loop to access the matrix rows
            for (int i = 0; i < rows; i++)
            {
                //Instantiate the matrix cols
                matrix[i] = new int[cols];

                //Create a for loop to access the matrix columns
                for (int j = 0; j < cols; j++)
                {
                    //Initialize the matrix entries to 0
                    matrix[i][j] = 0;
                }
            }
        }

        //Matrix method setMatrixEntry
        //Purpose: Sets the specified value to the specified column and row in the matrix
        public void setMatrixEntry(int r, int c, int value)
        {
            //Set matrix column and row to the supplied value
            matrix[r][c] = value;
        }

        //Matrix method getMatrixEntry
        //Purpose: Returns the value at the specified column and row in the matrix
        public int getMatrixEntry(int r, int c)
        {
            return matrix[r][c];
        }

        //Matrix method getRowSize
        //Purpose: Returns the size of rows for the matrix 
        public int getRowSize()
        {
            return rows;
        }

        //Matrix method getColumnSize
        //Purpose: Returns the size of columns for the matrix
        public int getColumnSize()
        {
            return cols;
        }

        //Matrix method print
        //Purpose: Prints the matrix to the Console
        public void print()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write(matrix[i][j] + "\t");
                }

                Console.Write("\n");
            }
        }

        //Matrix method +
        //Purpose: Adds two matrices and returns a new matrix with the added entries
        public static Matrix operator +(Matrix lhs, Matrix rhs)
        {
            //Declare a matrix to store values added between first and second matrix
            Matrix result;

            //Check if the column and row size are the same for the left and right matrices
            //FILL CODE HERE
            if (lhs.cols == rhs.cols && lhs.rows == rhs.cols)
            {
                //Instantiate the result matrix declared above
                //Ensure the size is equal to the left and right matrices
                //FILL CODE HERE
                result = new Matrix(lhs.rows, lhs.cols);

                //Add each entry of the left and right matrices and store it in the result matrix
                //Create a loop to get each row value
                //FILL CODE HERE
                for (int i = 0; i < lhs.cols; i++)
                {
                    //Create a loop to get each column value
                    //FILL CODE HERE
                    for (int j = 0; j < lhs.rows; j++)
                    {
                        //Calculate addition between matrix values and store in result matrix
                        //FILL CODE HERE
                        result.matrix[i][j] = lhs.matrix[i][j] + rhs.matrix[i][j];
                         
                    }
                }
            }
            //Otherwise the size of the left and right matrices are not equal
            else
            {
                //Set the result matix equal to null
                //FILL CODE HERE
                result = null;
                
            }

            //Return the result matrix
            return result;
        }
    }
}
