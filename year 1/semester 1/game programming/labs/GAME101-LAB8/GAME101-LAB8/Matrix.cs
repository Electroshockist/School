using System;

namespace GAME101_LAB8
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

        //Matrix method *
        //Purpose: Multiplies two matrices and returns a new matrix with the added entries
        public static Matrix operator *(Matrix lhs, Matrix rhs)
        {
            //Declare a matrix to store values multiplied between the left and right matrix
            Matrix result;

            //Check if the column size of left matrix is equal to the row size of right matrix
            //FILL CODE HERE
            if (lhs.cols == rhs.rows)
            {
                //Instantiate the result matrix declared above
                //Ensure the size is equal to the row size of the left matrix and the column size of the right matrix
                //FILL CODE HERE
                result = new Matrix(lhs.rows, rhs.cols);


                //Declare a variable to temporarily store the sum of matrix multiplication values
                //FILL CODE HERE
                int sum;
                //Calculate the value of the left and right matrices multiplied
                //Create a loop to access each row in the result matrix
                //FILL CODE HERE
                for (int i = 0; i < result.rows; i++)
                {
                    //Create a loop to access each column in the result matrix
                    //FILL CODE HERE
                    for (int j = 0; j < result.cols; j++)
                    {
                        //Initialize the variable which temporarily stores the matrix multiplication 
                        //FILL CODE HERE
                        sum = 0;

                        //Create a loop which iterates up to the column size of the left matrix 
                        //FILL CODE HERE
                        for (int k = 0; k < lhs.cols; k++)
                        {
                            //Calculate and store the multiplication of the matrix entries
                            //FILL CODE HERE
                            try
                            {
                                sum += lhs.matrix[j][k] * rhs.matrix[k][i];
                            }
                            catch(Exception e)
                            {
                                Console.WriteLine(e + " " );
                            }


                        }

                        //Store the multiplication result into the result matrix
                        //FILL CODE HERE
                        result.matrix[j][i] = sum;
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
