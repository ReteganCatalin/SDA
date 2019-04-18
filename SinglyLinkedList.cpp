#include "SinglyLinkedList.h"


SinglyLinkedList::SinglyLinkedList()
{
	head = new(node);
	head = NULL;
	size = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
	node* next = this->head;
	if (head == NULL)
	{
		return;
	}
	else
	{
		while (next->next != NULL)
		{
			node* current = next;
			next = next->next;
			delete current;
		}
		delete next;
	}
}

void SinglyLinkedList::Add_Value(TValue add_value)
{
	if (head == NULL)
	{
		node* new_node = new(node);
		new_node->info = add_value;
		new_node->next = NULL;
		head = new_node;
		size++;
	}
	else
	{
		node* CreateNode = new(node);
		CreateNode->info = add_value;
		CreateNode->next = head->next;
		head->next = CreateNode;
		size++;
	}
	
}

int SinglyLinkedList::Delete_Value(TValue delete_value)
{
	node* next_node = head;
	if (head == NULL)
	{
		return -1;
	}
	if (next_node->info == delete_value)
	{
		head = head->next;
		size--;
		return 1;
	}
	else
	{
		node* after_node = head->next;
		if (after_node == NULL)
		{
			return -1;
		}
		while (next_node->next->next != NULL && next_node->next->info != delete_value)
		{
			next_node = next_node->next;
		}
		if (next_node->next->next == NULL)
		{
			if (next_node->next->info == delete_value)
			{
				next_node->next = NULL;
				size--;
				return 1;
			}
			else
				return -1;
		}
		else
		{
			next_node->next = next_node->next->next;
			size--;
			return 1;
		}
	}
	
}

std::vector<TValue> SinglyLinkedList::GetList()
{
	node* next = new(node);
	next = head;
	vector<int> values;
	while (next != NULL)
	{
		values.push_back(next->info);
		next = next->next;
	}
	return values;
}
int SinglyLinkedList::GetElement(int position)
{
	node* node_next = new(node);
	node_next = head;
	for (int index = 0; index < position; index++)
		node_next = node_next->next;
	return node_next->info;
}

int SinglyLinkedList::GetSize()
{
	return size;
}

