using System;

namespace GAME101_LAB5
{
    class Program
    {
        static void Main(string[] args)
        {
            //Declare a string which will receive input from the user
            string ui;
            //Declare a string to contain the left portion of a string
            string sub1;
            //Declare a string to contain the right portion of a string
            string sub2;
            //placeholder to compare the two strings
            string comparer = "";

            //Ask the user to input a word
            Console.WriteLine("Type a word. I will check if it's a palindrome.");

            //Receive user input from the keyboard
            ui = Console.ReadLine();


            //Compare whether the string length is even
            if (ui.Length % 2 == 0) {
                //Assign the substring from the beginning to the mid-point of the user inputted string to the left string
                sub1 = ui.Substring(0, ui.Length / 2);

                //Assign the substring from the mid-point to the end of the user inputted string to the right string
                sub2 = ui.Substring(ui.Length / 2);
            }

            //Else
            else
            {
                //Assign the substring from the beginning to the mid-point of the user inputted string to the left string
                sub1 = ui.Substring(0, ui.Length / 2);

                //Assign the substring from the mid-point plus 1, to the end of the user inputted string to the right string
                sub2 = ui.Substring((ui.Length + 1) / 2);
            }
            //Reverse the right substring
            try
            {
                for (int i = sub2.Length; i > 0; i--)
                {
                    comparer += sub2[i - 1];
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }

            //Compare whether the left and right substrings are equal to eachother
            if (comparer == sub1)
            {
                //If they are equal, print the fact that the string is a palindrome
                Console.WriteLine("The word \"" + ui + "\" is a palindrome.");

            }
            
            //Else
            else
            {
                //If they are not equal, print the fact that the string is not a palindrome
                Console.WriteLine("The word \"" + ui + "\" is not a palindrome.");
            }
        }
    }
}
