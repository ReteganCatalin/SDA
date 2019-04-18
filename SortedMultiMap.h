#pragma once
#include "SinglyLinkedList.h"
#include "SMMIterator.h"
#include <vector>
#include <utility>
typedef int TKey;

typedef int TValue;


typedef std::pair<TKey, TValue> TElem;
typedef std::pair<TKey, SinglyLinkedList> TElement;


using namespace std;



typedef bool(*Relation)(TKey, TKey);



class SortedMultiMap {

	friend class SMMIterator;
struct SMMNode 
{
	TElement info;
	SMMNode* next;
};

private:

	/* representation of the SortedMultiMap */
	SMMNode* head;
	int size_of_map;
	Relation relation;

public:



	// constructor

	SortedMultiMap(Relation r);



	//adds a new key value pair to the sorted multi map

	void add(TKey c, TValue v);



	//returns the values belonging to a given key

	vector<TValue> search(TKey c) const;



	//removes a key value pair from the sorted multimap

	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed

	bool remove(TKey c, TValue v);



	//returns the number of key-value pairs from the sorted multimap

	int size() const;



	//verifies if the sorted multi map is empty

	bool isEmpty() const;



	// returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	

	SMMIterator iterator() const;


	TElem getElement(int position_node, int position_in_sll) const;
	
	int getSLLLenght(int position_node) const;

	// destructor

	~SortedMultiMap();

	vector<TValue> removeKey(TKey key);

};