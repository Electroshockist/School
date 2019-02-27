#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "HashTable.h"

using namespace std;

int main(void)
{
	ifstream ranking;
	string entry;
	string points;
	string size;

	ranking.open("fifa.txt");

	if (!ranking)
	{
		cerr << "Error: Could not open file" << endl;
		return -1;
	}

	ranking >> size;

	HashTable<int> leaderboard(atoi(size.c_str()));

	while (!ranking.eof())
	{
		ranking >> entry;
		ranking >> points;

		leaderboard.insert(entry, atoi(points.c_str()));
	}

	ranking.close();

	cout << "Original has table: " << endl;

	leaderboard.printTable();

	leaderboard.resize();

	cout << "Resized hash table: " << endl;

	leaderboard.printTable();

	cout << leaderboard.find("Canada") << endl;

	getchar();

	return 0;
}