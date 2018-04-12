using System;


namespace GAME101_LAB4
{
    class Matrix
    {
        //Declare a private integer representing the matrix row size
        private int row = 0;

        //Declare a private integer representing the matrix column size
        private int col = 0;

        //Declare a private two-dimensional integer matrix
        private int[,] multimatrix;

        //getter
        public int[,] GetMultimatrix
        {
            get
            {
             return multimatrix;        
            }
        }

        //Matrix Constructor
        //Purpose: Instantiate the matrix array and initialized each entry to 0
        public Matrix(int c, int r)
        {
            col = c;
            row = r;
            //Set the matrix column and row to the parameters supplied
            multimatrix = new int[col, row];

            //Instantiate the matrix rows
            //Create a for loop to access the matrix rows
            
                for (int i = 0; i < col; i++)
                {
                    //Instantiate the matrix columns
                    //Create a for loop to access the matrix columns
                    for (int j = 0; j < row; j++)
                    {
                    try
                    {
                        //Initialize the matrix entries to 0
                        multimatrix[i, j] = 0;
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("Error: " + e.Message);
                        Console.WriteLine("Failed to initiate array at multimatrix value "+ i +", " + j);
                    }
                }
            }  
        }
        //Matrix method setMatrixEntry
        //Purpose: Sets the specified value to the specified column and row in the matrix
        public void setMatrixEntry(int c, int r, int value)
        {
            this.multimatrix[c, r] = value;
        }
        //Matrix method isIdentityMatrix
        //Purpose: Determines whether the matrix is an identity matrix
        public bool isIdentityMatrix()
        {

            //Declare a boolean variable and initialize it to true
            bool idmatrix = true;
            bool forediag = true;
            bool backdiag = true;
            col = multimatrix.GetLength(0);
            row = multimatrix.GetLength(1);
            //Check if the matrix column size is not equal to the matrix row size
            if (col != row)
            {
                //Set the boolean variable to false
                idmatrix = false;
            }

            //Else matrix column size is equal to matrix row size
            else
            {
                //Create a for loop to access the forward matrix diagonal 

                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        //Check if matrix column and row entry is equal to 1 and loop counters are equal OR check if the matrix column and row entries are equal to 0
                        if (i != j && multimatrix[i,j] != 0)
                        {
                            idmatrix = false;
                        }
                        else if (i == j && multimatrix[i,j] != 1 && idmatrix == true)
                        {
                            forediag = false;
                        }
                    }
                }
                if (idmatrix == true && forediag == false)
                {
                    for (int i = row; i > 0; i--)
                    {
                        if (multimatrix[i, i] != 1) {
                            backdiag = false;
                        }
                    }
                }
                if (!forediag && !backdiag)
                {
                    idmatrix = false;
                }
            }
            return idmatrix;




            //Calculate the boolean variable AND true, and assign it to the boolean variable

            //Else


            //Calculate the boolean variable AND false, and assign it to the boolean variable

            //Return the boolean variable value
        }          
    }
}
