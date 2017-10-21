#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector{

	// Inserts the value into first position in ptr array that is 0
	friend istream &operator>>( istream &, Vector & );
	private:
		int size;
		static int count;    //by default, initialized to 0 anyway
	public:
		Vector(): size(0), ptr(0) {
			cout << "Default constructor" << endl;
		}
		//use this to initialize size, allocate array of len size and initialize all elements with 0
		Vector(int);  
		//getter for size
		int getSize() const;

		// A pointer to an array of ints
		// The data of Vector object
		int* ptr;

		//copy constructor (if source object has valid pointer ptr, then copy the 
		//values else give default constructor values to the destination object
		//make sure there is no self assignment i.e. source and destination are not same           
		Vector(const Vector &);
		//copy using operator overloading
		Vector& operator=(const Vector &);
		//determine if two Arrays are equal (return true/false)
		bool operator==(const Vector &) const;
		//destructor
		~Vector();		
};

#endif
