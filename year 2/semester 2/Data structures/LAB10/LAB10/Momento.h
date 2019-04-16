#ifndef MOMENTO_H
#define MOMENTO_H

class Momento
{
	friend class GuessGame;

	private:
		int number;

		Momento(int num)
		{
			number = num;
		}
};

#endif