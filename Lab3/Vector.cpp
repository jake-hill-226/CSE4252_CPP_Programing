#include "Vector.h"

//###########################################################################
//						Vector Class Definition
//###########################################################################

int Vector::count = 0;

Vector::Vector(int len){
	size = len;

	ptr =  new int[size];

	count ++;
}

Vector::Vector(const Vector & target){
	
	if(target.ptr == 0 || target.ptr == NULL){
		size = 0;
		ptr = 0;
	}
	else {
		size = target.getSize();

		ptr = new int[size];

		for(int i = 0; i < size; i++){
			*(ptr + i) = *(target.ptr + i);
		}
	}
	count ++;
}

int Vector::getSize() const{
	return size;
}

Vector& Vector::operator=(const Vector & target){
	if(this == &target){
		return *this;
	}

	size = target.size;
	ptr = new int[size];

	for(int i = 0; i < size; i++){
		*(ptr + i) = *(target.ptr + i);
	}

	return *this;
}

bool Vector::operator==(const Vector & rhs)const{
	if(this->size != rhs.getSize()){
		return false;
	}

	for(int i = 0; i < this->getSize(); i++){
		if(*(this->ptr + i) != *(rhs.ptr + i)){
			return false;
		}
	}

	return true;
}

istream &operator>>( istream & is, Vector & target){
	for(int i = 0; i < target.getSize(); i ++){
		is >> *(target.ptr + i);
	}

	return is;
}

Vector::~Vector(){
	delete[] ptr;
}

//###########################################################################
//					End of Vector Class Definition
//###########################################################################

void printVector(Vector & vec){
	cout << "[ ";
	for(int i = 0; i < vec.getSize() - 1; i++){
		cout << *(vec.ptr + i) << ", ";
	}
	cout << *(vec.ptr + vec.getSize() - 1) << " ] \n";
}

int main(){
	Vector v1(5);
	cout << "\nEnter "<< v1.getSize() << "integers:" << endl; 
	cin >> v1;           // invokes overloaded >> assignment
	Vector v2(v1);       // invokes copy constructor
	Vector v3 = v2;      // copies using overloaded operator =

	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
	cout << "v3: ";
	printVector(v3);
	cout << endl;
	if(v1 == v2){
		cout<<"Arrays are equal!"<<endl;
	}
	else{
		cout<<"Arrays are not equal!"<<endl;
	}
	return 0;
}

