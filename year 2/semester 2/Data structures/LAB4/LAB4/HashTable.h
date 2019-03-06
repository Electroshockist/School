#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

template <class Value>
class HashTable
{
	typedef string Key;

	class Node
	{
		friend class HashTable;

		public:
			Node() : key(""), value(NULL) {}
			Node(const Key& key, const Value& value) : key(key), value(value) {}

			const Key getKey() const          
			{ 
				return key; 
			}
			
			const Value getValue() const      
			{ 
				return value; 
			}

			void setValue(const Value& obj) 
			{ 
				value = obj; 
			}

		private:
			void setKey(const Key& index) 
			{ 
				key = index; 
			}

			Key key;
			Value value;
	};

	public:
		HashTable(size_t sz=0) : size(0), totalItems(0)
		{
			if(sz > 0)
			{
				//Resize to a prime number
				//Optimized to prevent collision
				size = getNextPrimeNum(sz);
			}

			table = new Node[size]();
		}

		~HashTable()
		{
			purge();

			delete [] table;
		}

		//Insert value into Hash Table
		Node insert(const Key& key, const Value& value)
		{
			//Find the hash value
			size_t index = hash(key);

			//Return key value if hash table is full
			if(totalItems == size)
				return table[index];

			while(table[index].getKey() != "")
			{
				//If key found replace value
				if(table[index].getKey() == key)
				{
					table[index].setValue(value);

					return table[index];
				}

				++index;
				index %= size;
			}

			//Insert slot
			table[index].setKey(key);
			table[index].setValue(value);
			
			++totalItems;

			return table[index];
		}

		//Remove key entry from Hash Table
		void remove(const Key& key)
		{
			//Find the hash value
			size_t index = hash(key);
			size_t originalIndex = index;

			while(table[index].getValue() != NULL) 
			{
				//If key found remove value
				if(table[index].getKey() == key)
				{
					table[index].key.clear();
					table[index].setValue(NULL);

					--totalItems;

					return;
				}
				
				//If key not found advance a slot
				++index;
				index %= size;

				//If slots do not contain key exit
				if(originalIndex == index)
					return;
			}
		}

		//Search for a key in the Hash Table
		Value find(const Key& key)
		{
			//Find the hash value
			size_t index = hash(key);
			size_t originalIndex = index;

			while(table[index].getValue() != NULL) 
			{
				//If key is found return value
				if(table[index].getKey() == key)
					return table[index].getValue();

				//If key not found advance a slot
				++index;
				index %= size;

				//If slots do not contain key return null
				if(originalIndex == index)
					return NULL;
			}

			return NULL;
		}

		void resize()
		{
			// Create a temporary node pointer which points to table
			// This will create a reference to the original hash table
			Node* tempTable = table;

			// Create a size_t variable and store the size of the original table
			// This will keep a reference to the original hash table size
			size_t tempSize = size;

			// Create an if statement to check whether the size is great than 0
			// If it is greater than 0, set double the size and find the next prime number
			// This will double the size of your hash table and search for the next closest prime number
			
			//BEGIN IF
			if (size > 0) {
				size = getNextPrimeNum(size * 2);
			}
			
			//END IF

			// Instantiate table with the new size
			// This will create a new hash table which is double the size of the original
			table = new Node[size]();

			// Create a loop to traverse all indices in the original hash table
			// This will allow you to copy the information stored in the original hash table, and insert it into the new hash table
			
			//BEGIN LOOP
			for (size_t i = 0; i < tempSize; i++) {
				// Insert the key and value from the original hash table into the new table
				// Use the insert method to create a new entry in the new hash table
				insert(tempTable[i].getKey(), tempTable[i].getValue());


				// Erase the key from the original hash table at index i
				tempTable[i].key.clear();


				// Erase the value from the original hash table at index i
				tempTable[i].setValue(NULL);
			}
				
			//END LOOP

			// Delete the original hash table
			delete[] tempTable;
			
		}

		void purge()
		{
			delete [] table;
			table = NULL;

			size = 0;
			totalItems = 0;
		}

		//Prints all entries
		void print() const
		{
			for (size_t i=0; i<size; i++)
			{
				printEntry(table[i]);
				cout << endl;
			}
			cout << endl;
		}

		//Prints a single entry
		void printEntry(const Node entry) const
		{
			if (entry.getKey() != "")
				cout << entry.getKey() << ":" << entry.getValue();
		}

		//Prints the table structure
		void printTable() const
		{
			for (size_t i=0; i<size; i++) {
				cout << i << ":\t";
				Node iter = table[i];
				printEntry(iter);
				cout << endl;
			}
			cout << endl;
		}

		size_t getSize()
		{
			return size;
		}

		size_t getTotalItems()
		{
			return totalItems;
		}

	private:
		//An array of Nodes
		Node *table;

		//Number of table slots
		size_t size;

		//Number of items
		size_t totalItems;

		//The hash function
		size_t hash(const Key& str)
		{
			size_t hash = 0;

			//Iterates through each character within the key
			for (size_t i=0; i<str.length(); i++)
			{
				hash = hash * 256 + str[i];
			}

			return hash % size;
		}

		//Determines whether val is a prime number
		bool isNumPrime(size_t val)
		{
			for(size_t i = 2; (i * i) <= val; i++)
			{
				if((val % i) == 0)
					return false;
			}

			return true;
		}

		//Determines the next prime number closest to val
		size_t getNextPrimeNum(size_t val)
		{
			size_t i;

			for(i = val + 1; ; i++)
			{
				if(isNumPrime(i))
					break;
			}

			return i;
		}
};

#endif // HASHTABLE_H