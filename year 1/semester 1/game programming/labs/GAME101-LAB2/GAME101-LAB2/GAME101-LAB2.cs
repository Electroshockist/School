using System;

namespace GAME101_LAB2
{
    class Program
    {
        static void Main(string[] args)
        {
            // Declare an integer to hold grade average
            int x = 0;

            // Prompt for assignment 1 grade
            Console.WriteLine("Input 10 grades.");
            Console.Write("Grade 1: ");

            // Receive user input
            int a = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 2 grade
            Console.Write("Grade 2: ");
            // Receive user input
            int b = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 3 grade
            Console.Write("Grade 3: ");
            // Receive user input
            int c = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 4 grade
            Console.Write("Grade 4: ");
            // Receive user input
            int d = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 5 grade
            Console.Write("Grade 5: ");
            // Receive user input
            int e = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 6 grade
            Console.Write("Grade 6: ");
            // Receive user input
            int f = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 7 grade
            Console.Write("Grade 7: ");
            // Receive user input
            int g = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 8 grade
            Console.Write("Grade 8: ");
            // Receive user input
            int h = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 9 grade
            Console.Write("Grade 9: ");
            // Receive user input
            int i = Convert.ToInt32(Console.ReadLine());

            // Prompt for assignment 10 grade
            Console.Write("Grade 10:");
            // Receive user input
            int j = Convert.ToInt32(Console.ReadLine());

            // Calculate average grade
            x = (a + b + c + d + e + f + g + h + i + j) / 10;

            // Print average grade to the Console
            Console.WriteLine("The average grade is " + x + ".");

            // Compare average grade to determine letter grade
            // Print average letter grade to the Console
            if (x >= 90)
            {
                Console.WriteLine("The average grade is an A+. Good Job.");
            }
            else if (x < 90 && x > 80)
            {
                Console.WriteLine("The average grade is an A.");
            }
            else if (x < 80 && x > 70)
            {
                Console.WriteLine("The average grade is an B.");
            }
            else if (x < 70 && x > 60)
            {
                Console.WriteLine("The average grade is an C.");
            }
            else if (x < 60 && x > 50)
            {
                Console.WriteLine("The average grade is an D.");
            }
            else if (x < 50)
            {
                Console.WriteLine("The average grade is an F. Your class is failing.");
            }
        }
    }
}
