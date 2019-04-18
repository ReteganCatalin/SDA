#pragma once

#include <vector>
typedef int TKey;

typedef int TValue;


typedef std::pair<TKey, TValue> TElem;



using namespace std;



typedef bool(*Relation)(TKey, TKey);


struct node
{
	TKey info;
	node* next;
};
class SinglyLinkedList
{
private:
	int size;
	node* head;
public:
	SinglyLinkedList();
	void Add_Value(TValue add_value);
	int Delete_Value(TValue delete_value);
	std::vector<TValue> GetList();
	int GetElement(int value);
	int GetSize();
	~SinglyLinkedList();
};