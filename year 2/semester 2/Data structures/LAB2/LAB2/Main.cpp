#include "CDList.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
void CDList<T>::getJosephusPosition(int m)
{
	//Declare two pointers to two nodes and set them equal to head
	Node* n1 = head;
	Node* n2 = head;

	//Loop until there is only one node
	while (n1->next != n1) {

		//Loop until counter equals m
		for (size_t i = 1; i < m; i++)	{
			//Set second pointer equal to first pointer and first pointer to the next node 
			n2 = n1;
			n1 = n1->next;
		}


		//Declare a temp node pointer and set equal to first pointer
		Node* temp = n1;

		//Print value of node to be deleted
		cout << temp->value << endl;

		//Relink nodes and erase temp node
		n1 = temp->next;
		n1->prev = n2;
		n2->next = n1;

		erase(temp);
	}
	

	//Print value of last node
	cout << n1->value << endl;
	getchar();
}

int main()
{
	CDList<string> sentence;
	CDList<string>::Iterator word = sentence.begin();

	for (int i = 0; i < 8; i++)
	{
		sentence.push_back("Person " + to_string(i + 1));
	}

	sentence.getJosephusPosition(2);
}
