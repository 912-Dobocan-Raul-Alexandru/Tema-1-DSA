#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
Bag::Bag() {
	//Bag constructor
	this->capacity=1;
    this->minimum=NULL_TELEM;
    this->maximum=NULL_TELEM;
	this->frequencies = new TElem[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->frequencies[i] = 0;
	}
}
/*
 * there are no worst case-best-case
 * The complexity is O(n),where  n is maximum-elem
 */
void Bag::resize(TElem minimum, TElem maximum,TElem elem){
	//resize the bag
	int new_capacity=maximum - elem + 1;
	TElem* newFrequencies = new TElem[2*new_capacity];
	for (int i = 0; i < new_capacity;i++) {
		newFrequencies[i] = 0;
	}
	for(int i=0;i<this->capacity;i++){
		if (this->frequencies[i]!=0)
			newFrequencies[i+(this->minimum-elem)]=this->frequencies[i];
	}
    this->minimum=elem;
	delete[] this->frequencies;
	this->capacity = 2*new_capacity;
	this->frequencies = newFrequencies;
}
/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
void Bag::add(TElem elem) {
	//Minimum element becomes the first element and has index 0,if another element is added and it is smaller than the minimum, the minimum becomes the new element
	//If the element is already in the bag, the frequency of the element is increased
	//If the element is not in the bag, the element is added to the bag and the frequency is set to 1 and the capacity of the bag is increased
	//The new element takes the position elem-minimum in the bag
	if (this->minimum==NULL_TELEM){
		this->frequencies[0]=1;
		this->minimum=elem;
		this->maximum=elem;
	}
	else{
		if(elem<this->minimum){
			this->resize(this->minimum,this->maximum,elem);
			this->frequencies[0]=1;
		}
		else if(elem>this->maximum){
			this->maximum=elem;
			this->resize(this->minimum,this->maximum,this->minimum);
			this->frequencies[this->maximum-this->minimum]=1;
		}
		else{
			int position = elem - this->minimum;
			if(this->frequencies[position] == 0){
				this->frequencies[position]=1;
			}
			else{
				this->frequencies[position]++;
			}
		}
	}
}

/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
bool Bag::remove(TElem elem) {
	// removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	if(this->minimum==NULL_TELEM || elem<this->minimum || elem>this->maximum){
		return false;
	}
	else{
		int position = elem - this->minimum;
		if(this->frequencies[position] == 0){
			return false;
		}
		else{
			this->frequencies[position]--;
			return true;
		}
	}
	return false;
}
/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
void Bag::empty()
{
    this->minimum=NULL_TELEM;
    this->maximum=NULL_TELEM;
}
/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
bool Bag::search(TElem elem) const {
    if(this->minimum==NULL_TELEM || elem<this->minimum || elem>this->maximum)
        return false;
	if(this->frequencies[elem-this->minimum]>0){
			return true;
		}
	return false;
}
/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
int Bag::nrOccurrences(TElem elem) const {
    if(this->minimum==NULL_TELEM || elem<this->minimum || elem>this->maximum)
        return 0;
	return this->frequencies[elem-this->minimum];
}

/*
 * there are no worst case-best-case
 * The complexity is O(n),where  n is the interval [minimum,maximum]
 */
int Bag::size() const {
	//returns the number of elements from the bag
	int thesize=0;
    int real_capacity=this->maximum-this->minimum+1;
	for(int i=0;i<real_capacity;i++){
        thesize+=this->frequencies[i];
	}

    return thesize;
}

/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
bool Bag::isEmpty() const {
	if (this->minimum==NULL_TELEM)
		return true;
	return false;
}
/*
 * there are no worst case-best-case
 * The complexity is O(n),where n is the interval [minimum,maximum]
 */
BagIterator Bag::iterator() const {
	//returns an iterator for this bag
	return BagIterator(*this);
}
/*
 * there are no worst case-best-case
 * The complexity is O(1)
 */
Bag::~Bag() {
	delete[] this->frequencies;
}

