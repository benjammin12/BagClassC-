/* Ben Xerri: Testing all methods for bag class

*/

#include <iostream>
#include "bag.h"
using namespace std;

int main() {
	bag a;
	a.insert(10); //test insert
	a.insert(20);
	a.insert(25);
	cout << "our bag should have 10,20,25 in it: " << a << endl;
	a.erase(25); //test delete
	a.insert(12);
	cout << "our bag should have 10,20,12 in it: " << a << endl;
	bag b(3);
	b.insert(23);
	b.insert(25);
	b.insert(27);
	b.insert(29); //test reserve function
	cout << "our bag shoule have 23,25,27, and 29 in it: " << b << endl;


	b = a; //test assignment operator

	cout << "b should be a: " << b << endl; //b is now the same as a, so it works
	a+=(b); //test += operator
	cout << "a should be a += b:: " << a << endl; //since we made b, a we have a repeated twice which works
	int numTwentys = a.count(20); //count number of twentys
	cout << "Number of twentys in a is: "  << numTwentys << endl; //test count, we get an output of 2 which is correct
	
	a.erase_one(20);  //test erase one
	cout << a << endl; //1 twenty is missing, so it works
	a.erase(12); // test erase all 12s
	cout << a << endl; // all twelves are gone in print statement

	int hold;
	cin >> hold;


}

