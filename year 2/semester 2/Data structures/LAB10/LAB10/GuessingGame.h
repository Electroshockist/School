#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "Momento.h"

using namespace std;

class GuessGame 
{
	public:
		Momento* join() 
		{
			srand((unsigned)time(&t));

			return new Momento(rand() % 30 + 1);
		}

		int evaluateGuess(Momento* m, int guess) 
		{
			if (guess == m->number) 
				return 0;
			else if (guess > m->number)
				return 1;
			else
				return -1;
		}

	private:
		time_t  t;
};

#endif