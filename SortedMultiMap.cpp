#include "SortedMultiMap.h"

SortedMultiMap::SortedMultiMap(Relation r)
{
	head = NULL;
	this->relation = r;
	
	size_of_map = 0;
}

void SortedMultiMap::add(TKey key,TValue v)
{
	///O(n+m)
	SMMNode* next_node = new(SMMNode);
	if (head == NULL)
	{
		head = next_node;
		TElement value = std::make_pair(key, SinglyLinkedList());
		head->next = NULL;
		head->info = value;
		head->info.second.Add_Value(v);
		size_of_map++;
	}
	else
	{
		SMMNode* after_node = new(SMMNode);
		if (relation(head->info.first, key) == false)
		{
				SMMNode* create_node = new(SMMNode);
				create_node->next = head->next;
				create_node->info = head->info;
				TElement value = std::make_pair(key, SinglyLinkedList());
				head->next = create_node;
				head->info = value;
				head->info.second.Add_Value(v);
				size_of_map++;		
		}
		else
		{
			{
				next_node = head;
				if (head->info.first == key)
				{
					head->info.second.Add_Value(v);
					size_of_map++;
				}
				else
				{
					after_node = head->next;
					while (after_node != NULL && relation(after_node->info.first, key) == true)
					{
						next_node = next_node->next;
						after_node = after_node->next;
					}
					if (after_node == NULL)
					{
						if (next_node->info.first == key)
						{
							next_node->info.second.Add_Value(v);
							size_of_map++;
						}
						else
						{
							SMMNode* create_node = new(SMMNode);
							create_node->next = NULL;
							create_node->info = std::make_pair(key, SinglyLinkedList());
							next_node->next = create_node;
							create_node->info.second.Add_Value(v);
							size_of_map++;
						}
						
					}
					else
					{
						if (next_node->info.first == key)
						{
							next_node->info.second.Add_Value(v);
							size_of_map++;
						}
						else
						{
							SMMNode* create_node = new(SMMNode);
							create_node->info = std::make_pair(key, SinglyLinkedList());
							create_node->next = next_node->next;
							create_node->info.second.Add_Value(v);
							next_node->next = create_node;
							size_of_map++;
						}
				}
				
				}
			}
		}
	}
}

std::vector<TValue> SortedMultiMap::search(TKey key) const
{
	///O(n+m)
	SMMNode* next_node = new(SMMNode);
	next_node = head;
	std::vector<int> values;
	while (next_node != NULL && next_node->info.first!=key)
	{
		next_node=next_node->next;
	}
	if (next_node == NULL)
	{
		return values;
	}
	else
	{
		values = next_node->info.second.GetList();
	}
	return values;
}
bool SortedMultiMap::remove(TKey key, TValue v)
{
	///O(n+m)
	int removed;
	SMMNode* next_node = new(SMMNode);
	next_node = head;
	if (head == NULL)
	{
		return false;
	}
	else
	{
		SMMNode* after_node = new(SMMNode);
		if (head->info.first == key)
		{
			removed = head->info.second.Delete_Value(v);
			if (removed == 1 && head->info.second.GetSize() == 0)
			{
				head = head->next;
			}
			if (removed == 1)
			{
				size_of_map--;
				return true;
			}
			return false;
		}
		else
		{
			after_node = head->next;
			while (after_node != NULL && after_node->info.first != key)
			{
				next_node = next_node->next;
				after_node = after_node->next;
			}
			if (after_node == NULL)
			{
					return false;
			}
			else
			{
				removed = after_node->info.second.Delete_Value(v);
				if (removed == 1 && after_node->info.second.GetSize() == 0)
				{
					next_node->next = after_node->next;
				}
				if (removed == 1)
				{
					size_of_map--;
					return true;
				}
				return false;
			}
		}
			
	}
}
int SortedMultiMap::getSLLLenght(int position) const
{
	///O(n)
	SMMNode* node = new(SMMNode);
	node = head;
	for (int index = 0; index < position; index++)
		node = node->next;
	return node->info.second.GetSize();
}

TElem SortedMultiMap::getElement(int node_position,int position_in_sll) const
{
	///O(n+m)
	SMMNode* node = new(SMMNode);
	node = head;
	for (int index = 0; index < node_position; index++)
		node = node->next;
	int value = node->info.second.GetElement(position_in_sll);
	TElem new_element = make_pair(node->info.first, value);
	return new_element;
}

SMMIterator SortedMultiMap::iterator() const
{
	return SMMIterator(*this);
}
int SortedMultiMap::size() const
{
	//theta(1)
	return size_of_map;
}
bool SortedMultiMap::isEmpty() const
{
	//theta(1)
	return size_of_map == 0;
}
SortedMultiMap::~SortedMultiMap()
{
	if (head == NULL)
	{
		return;
	}
	SMMNode* delete_node = new(SMMNode);
	delete_node = head->next;
	while (delete_node != NULL)
	{
		delete head;
		head = delete_node;
		delete_node = delete_node->next;
	}
	delete head;
}
vector<TValue> SortedMultiMap::removeKey(TKey key)
{
	///O(n+m)
	vector<TValue> values;
	if (head == NULL)
	{
		return values;
	}
	else
	{
		if (head->next == NULL)
		{
			if (head->info.first == key)
			{
				values = head->info.second.GetList();
				head = NULL;
				size_of_map -= values.size();
				return values;
			}
			else
				return values;
		}
		else
		{
			SMMNode* node1 = new(SMMNode);
			SMMNode* node2 = new(SMMNode);
			node1 = head;
			node2 = head->next;
			while (node2->next != NULL && relation(node2->next->info.first, key) == true)
			{
				node1 = node1->next;
				node2 = node2->next;
			}
			if (node2->next == NULL)
			{
				if (node2->info.first == key)
				{
					values = node2->info.second.GetList();
					node1->next = NULL;
					size_of_map -= values.size();
					return values;
				}
				return values;
			}
			else
			{
				if (node2->info.first == key)
				{
					values = node2->info.second.GetList();
					node1->next = node2->next;
					size_of_map -= values.size();
					return values;
				}
				return values;
			}
		}
	}
}