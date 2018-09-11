using System;

namespace GAME101_LAB6
{
    class Program
    {
        static void Main(string[] args)
        {
            Shape s;
            char selection;
            string color, name;
            int width, height;
            bool quit = false;

            while (!quit)
            {
                Console.WriteLine("Select the shape you wish to create.");
                Console.WriteLine("(R) Rectangle\n(E) Ellipse\n(Q) Quit");

                selection = Console.ReadKey().KeyChar;

                Console.Clear();

                switch (selection)
                {
                    case 'R':
                    case 'r':
                        Console.WriteLine("Enter the name of the shape: ");
                        name = Console.ReadLine();

                        Console.WriteLine("Enter the color of the shape: ");
                        color = Console.ReadLine();

                        Console.WriteLine("Enter the width/minor of the shape: ");
                        width = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter the height/major of the shape: ");
                        height = Convert.ToInt32(Console.ReadLine());

                        s = new Rectangle(width, height, name, color);

                        Console.WriteLine("The are of the " + s.getShapeType() + " is " + s.area());
                        break;
                    case 'E':
                    case 'e':
                        Console.WriteLine("Enter the name of the shape: ");
                        name = Console.ReadLine();

                        Console.WriteLine("Enter the color of the shape: ");
                        color = Console.ReadLine();

                        Console.WriteLine("Enter the width/minor of the shape: ");
                        width = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter the height/major of the shape: ");
                        height = Convert.ToInt32(Console.ReadLine());

                        s = new Ellipse(width, height, name, color);

                        Console.WriteLine("The area of the " + s.getShapeType() + " is " + s.area());
                        break;
                    case 'Q':
                    case 'q':
                        quit = true;
                        break;
                    default:
                        Console.WriteLine("Invalid selection.");
                        break;
                }
            }
        }
    }
}
