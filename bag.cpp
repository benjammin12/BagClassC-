#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include "bag.h"
using namespace std;

typedef int value_type; //used to declare all our typdefs, named value_types
typedef std::size_t size_type; // used to declare all ou sizes
bag::bag(size_type initial_capacity) //set capacity, used, and do a dynamic array of value_type
{
	data = new value_type[initial_capacity];
	used = 0;
	capacity = initial_capacity;
}

bag::~bag() //our destructor should release any dynamic memory we've allocated , called automatically when the object drops out of scope
{
	delete [] data;
}


void bag::reserve(size_type new_capacity) //we enlarge our bag, but it should still have the same contents
{
	
	value_type *temp = new value_type[new_capacity]; 
	for (int i = 0; i < capacity; i++) {
		temp[i] = data[i];
	}
	delete[] data; //done with data, now delete it
	data = temp;
	
	// then copy all the elements , then delete the old dynamic array to prevent memory leak, then repoint data
	capacity = new_capacity;
}

bool bag::erase_one(const value_type& target) //erases one item of a given value, returns true if something got erased, 0 if not
{
	
	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			data[i] = data[used - 1];
			used--;
			return true;
		}
	}
	return false;
}

size_type bag::erase(const value_type& target) //erases all of the data target from the bag
{
	size_type counter = 0;
	
	while (erase_one(target))
	{
		counter++;
	}
	return counter;
}

void bag::insert(const value_type& entry) //inserts an entry into the bag
{
	if (used == capacity) //if our array is full, enlarge it
		reserve(capacity * 2);

	data[used] = entry; //then we can add it
	used++;
}

void bag::operator +=(const bag& addend) //adds the contents of one bag to another
{
	for (int i = 0; i < addend.used ; i++) {
		this->insert(addend.data[i]);
	}
}

void bag::operator = (const bag& source) //makes two bags equal
{
	used = 0;
	for (int i = 0; i < source.used; i++) {
		this->insert(source.data[i]);
	}
}

size_type bag::count(const value_type& target) const //returns how many things are currently in the bag
{
	int numTarget = 0;

	for (int i = 0; i < used; i++) {
		if (data[i] == target)
			numTarget++;
	}

	return numTarget;
}

ostream& operator <<(ostream& outs, const bag& source)
{
	for (unsigned int r = 0; r<source.used; r++)
	{
		outs << source.data[r] << ",";
	}
	//outs<<endl;
	return outs;
}