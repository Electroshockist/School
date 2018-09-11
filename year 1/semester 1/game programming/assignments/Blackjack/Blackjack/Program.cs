using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blackjack
{
    class Program
    {
        static void Main(string[] args)
        {
            //sets an array to be a template deck with 13 columns(numbers) and 4 rows(suits)
            bool[,] deck = new bool[4, 13];
            //sets suits names to be displayed to the user
            string[] displaysuit =
                {
                "Hearts", //0
                "Spades",
                "Diamonds",
                "Clubs"
                };
            //sets facecard(and ace) names to be displayed to the user
            string[] displayface =
                {
                "Ace",
                "Jack",
                "Queen",
                "King"
                };
            void getCard()
            {
                try
                {
                    //generates random noise
                    Random randomgen = new Random();
                    //generates random int between 0 and a set value using generated noise to generate a suit
                    int randomsuit = randomgen.Next(0, deck.GetLength(0));
                    int randomcard = randomgen.Next(0, deck.GetLength(1));
                    //displays the card
                    //check if ace
                    if (randomcard == 0)
                    {
                        Console.WriteLine(displayface[randomcard] + " of " + displaysuit[randomsuit]);
                    }
                    //check if face card
                    else if (randomcard > 9)
                    {
                        Console.WriteLine(displayface[randomcard - 9] + " of " + displaysuit[randomsuit]);
                    }
                    else
                    {
                        Console.WriteLine(randomcard + 1 + " of " + displaysuit[randomsuit]);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("An error has occured while trying to get a card: " + e.Message);
                }
            }

            //for testing purposes only
            void testDeck()
            {
                Console.WriteLine("Counting cards... ");
                try
                {
                    //i is used to track the suit
                    for (int i = 0; i < deck.GetLength(0); i++)
                    {
                        Console.WriteLine("____________________");
                        Console.WriteLine(displaysuit[i]);
                        //j is used to track the card
                        for (int j = 0; j < deck.GetLength(1); j++)
                        {
                            //for debugging purposes only
                            //displays ace of each suit
                            if (j == 0)
                            {
                                Console.WriteLine(displayface[0] + " of " + displaysuit[i] + ", ");
                            }
                            //displays faces of each suit
                            else if (j > 9)
                            {
                                Console.WriteLine(displayface[j - 9] + " of " + displaysuit[i] + ", ");
                            }
                            //displays numbers of each suit
                            else
                            {
                                Console.WriteLine(j + 1 + " of " + displaysuit[i] + ", ");
                            }
                        }
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("An error has occurred while trying to test the deck: " + e.Message);
                }
            }//end of testDeck function
            getCard();
        }
    }
}
