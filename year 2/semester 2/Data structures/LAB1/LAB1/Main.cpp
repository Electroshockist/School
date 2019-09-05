#include <iostream>
#include <string>
using namespace std;

#include "DList.h"

int main(void)
{
	DList<string> sentence;
	DList<string>::Iterator word;

	sentence.push_back("Element 2");
	sentence.push_front("Element 1");
	sentence.push_back("Element 3");
	
	for (word=sentence.begin(); word!=sentence.end(); ++word)
		cout << *word << ' ';
	cout << endl;

	sentence.pop_back();
	sentence.push_back("Element 4");

	for (word=sentence.begin(); word!=sentence.end(); ++word)
		cout << *word << ' ';
	cout << endl;

	word = sentence.find("Element 2");
	if (word != sentence.end()) {
		word = sentence.erase(word);
		sentence.insert(word, "Element 5");
	}

	for (word=sentence.begin(); word!=sentence.end(); ++word)
		cout << *word << ' ';
	cout << endl;


	DList<int> sequence;
	DList<int>::Iterator num;

	for (int i=0; i<10; i++)
		sequence.push_back(i);

	for (num=sequence.begin(); num!=sequence.end(); ++num)
		cout << *num << ' ';
	cout << endl;

	// square all numbers in sequence
	for (num=sequence.begin(); num!=sequence.end(); ++num)
		*num *= *num;

	for (num=sequence.begin(); num!=sequence.end(); ++num)
		cout << *num << ' ';
	cout << endl;

	// remove all odd numbers
	for (num=sequence.begin(); num!=sequence.end(); /* nothing */)
		if (*num % 2)
			num = sequence.erase(num);
		else
			++num;

	for (num=sequence.begin(); num!=sequence.end(); ++num)
		cout << *num << ' ';
	cout << endl;

	// print the list in reverse order
	for (num=sequence.rbegin(); num!=sequence.rend(); --num)
		cout << *num << ' ';
	cout << endl;

	getchar();
}
