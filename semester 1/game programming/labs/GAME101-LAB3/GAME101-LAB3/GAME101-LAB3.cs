using System;

namespace GAME101_LAB3
{
    class Program
    {
        static void Main(string[] args)
        {
            // Declare integers to hold grade and average
            int[] grade = new int[10];
            int avg = 0;
            //surrogate variable for i
            int j;

            // Use a loop to receive an integer grade
            for (int i = 0; i < 10; i++)
            {
                // Start exception handling
                try
                {
                    j = i + 1;
                    Console.Write("Enter grade " + j + ": ");
                    // Prompt for assignment 1 grade
                    //Receive user input
                    grade[i] = Convert.ToInt32(Console.ReadLine());

                    // Check if grade is a valid integer input between 0 - 100
                    // Otherwise prompt an error and reset loop
                    if (grade[i] < 0 || grade[i] > 100)
                    {
                        Console.WriteLine("Error: Input a value between 0 and 100");
                        Console.WriteLine("Please try again.");
                        i--;
                    }
                    else
                    {
                        avg += grade[i];
                    }
                   
                }
                // Catch exception by prompting an error and reset the loop
                catch (Exception e)
                {
                    Console.WriteLine("Error: " + e.Message);
                    Console.WriteLine("Please try again.");
                    i--;
                }

                // Calculate average grade
                if (i == 9)
                {
                    avg = avg / grade.Length;
                    Console.WriteLine("The average grade is " + avg);
                    
                        if (avg >= 90) {
                        
                            Console.WriteLine("Your class received an A+");
                        }
                        else if (avg >= 80)
                        {
                            Console.WriteLine("Your class received an A");
                        }
                        else if (avg >= 70)
                        {
                            Console.WriteLine("Your class received a B");
                        }
                        else if (avg >= 60)
                        {
                            Console.WriteLine("Your class received a C");
                        }
                        else if (avg >= 50)
                        {
                            Console.WriteLine("Your class received a D");
                        }
                        else
                        {
                            Console.WriteLine("Your class received an F");
                        }
                }
            }
            


            // Print average grade to the Console


            // Compare average grade to determine letter grade
            // Print average letter grade to the Console

        }
    }
}
