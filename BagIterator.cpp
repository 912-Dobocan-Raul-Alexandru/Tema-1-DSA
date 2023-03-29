#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	current=0;
}

int BagIterator::first() {
	return bag.frequencies[0];
}


void BagIterator::next() {
	if (valid())
		current++;
	else
		throw exception();
}


bool BagIterator::valid() const {
	if (current<bag.size())
		return true;
	else
		return false;
}



TElem BagIterator::getCurrent() const
{
	if (valid())
		return bag.nrOccurrences(current);
	else
		return NULL_TELEM;
}
