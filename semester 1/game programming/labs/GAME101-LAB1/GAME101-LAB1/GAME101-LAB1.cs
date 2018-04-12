using System;

namespace GAME101_LAB1
{
    class Program
    {
        static void Main(string[] args)
        {
            // Declare integer variables x, y and temp
            // ENTER CODE HERE
            //i is a surrogate variable; it holds x's value while we transfer y's value to x
            int i = 0;
            int x = 0;
            int y = 0;
            

            // Prompt user to input an integer
            // ENTER CODE HERE
            Console.Write("Determine value of 'x': ");

            // Store integer in variable x
            // ENTER CODE HERE
            x = Convert.ToInt32(Console.ReadLine());


            // Prompt user to input an integer
            // ENTER CODE HERE
            Console.Write("Determine value of 'y': ");

            // Store integer in variable y
            // ENTER CODE HERE
            y = Convert.ToInt32(Console.ReadLine());

            // Swap the values for x and y
            // ENTER CODE HERE
            //i becomes surrogate
            //i hlods x's value
            i = x;
            //x become y
            x = y;
            //y becomes x via i
            y = i;


            // Print the values for x and y to the Console
            // ENTER CODE HERE
            Console.Write("Swapping values...");
            //I could have just made it look like I was swapping the values by typing x = y and y = x, but that would not have actually been changing the variables
            Console.Write("\nx = " + x + " and y = " + y + "!\n");
        }
    }
}
