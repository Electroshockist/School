#ifndef GAME_H
#define GAME_H

#include "Momento.h"

class Game 
{
	public:
		Game() 
		{ 
			min = 1;  
			max = 30;  
			done = 0; 
		}

		void setMomento(Momento *m)
		{
			momento = m;
		}

		Momento* getMomento()
		{
			return momento;
		}

		char name[20];
		int  min, max, done;
	
	private:
		Momento* momento;	
};

#endif