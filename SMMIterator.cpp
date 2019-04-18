#include "SMMIterator.h"
SMMIterator::SMMIterator(const SortedMultiMap& c) : con(c) {
	this->current = 0;
	this->currentValues = 0;
	this->numberOfPairs = 0;
}

void SMMIterator::first()
{
	//theta(1)
	current = 0;
	currentValues = 0;
	numberOfPairs = 0;
}

void SMMIterator::next()
{
	//theta(1)
	if (this->valid() == false)
	{
		throw std::exception("invalid iterator");
	}
	else
	{
		if (currentValues < con.getSLLLenght(current)-1)
		{
			currentValues++;
		}
		else
		{
			current++;
			currentValues = 0;
		}
		numberOfPairs++;
	}
}

bool SMMIterator::valid() const
{
	//theta(1)
	return numberOfPairs < con.size();
}


TElem SMMIterator::getCurrent() const
{
	//theta(1)
	if (this->valid() == false)
	{
		throw std::exception("invalid iterator");
	}
	return con.getElement(current,currentValues);
	
}