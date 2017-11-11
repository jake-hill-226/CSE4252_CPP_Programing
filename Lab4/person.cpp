#include <iostream>
#include <string>
using namespace std;

class Person {
	public:
		//define the constructor
		Person(string name, string address){
			this->name = name;
			this->address = address;
		}
		//define getters for the variables

		string getName(){
			return name;
		}
		string getAddress(){
			return address;
		}
	private:
		string name;
		string address;
};
class Employee : public Person {
	public:
		//define the constructor
		Employee(string name, string address, double salary) : Person(name, address){
			this->salary = salary;
		}

		double getSalary(){
			return salary;
		}
	private:
		double salary;
};
class Student : public Person {
	public:
		//define the constructor
		Student(string name, string address, int numUnits, string residence) : Person(name, address){
			this->numUnits = numUnits;
			this->residence = residence;
		}

		int getUnits(){
			return numUnits;
		}
		string getResidence(){
			return residence;
		}
	private:
		int numUnits;
		string residence;
};
class TeachingAssistant : public Employee {
	public:
		//define the constructor
		TeachingAssistant(string name, string address, double salary, string course) 
							: Employee(name, address, salary){
			this->course = course;
		}
		string getCourse(){
			return course;
		}
	private:
		string course;
};
int main () {
	//create instances of each and check the implementation (although nothing much to check)

	Person p("Jake The Snake", "4419 Sclan'n Way");
	Employee e("Bob", "745 Spaceship way", 50000.00);
	Student s("Bonny", "N/A", 15, "Mearl Towers");
	TeachingAssistant ta("Luis", "559 hellsway", 15000.00, "ART1: Underwater Basket Weavning");

	cout << "sizeof(Person): " << sizeof(Person) << " bytes." << endl;
	cout << "\tname: " << p.getName() << endl;
	cout << "\taddress: " << p.getAddress() << endl;
	cout << "sizeof(Employee): " << sizeof(Employee) << " bytes." << endl;
	cout << "\tname: " << e.getName() << endl;
	cout << "\taddress: " << e.getAddress() << endl;
	cout << "\tsalary: " << e.getSalary() << endl;
	cout << "sizeof(Student): " << sizeof(Student) << " bytes." << endl;
	cout << "\tname: " << s.getName() << endl;
	cout << "\taddress: " << s.getAddress() << endl;
	cout << "\tnumUnits: " << s.getUnits() << endl;
	cout << "\tresidence: " << s.getResidence() << endl;
	cout << "sizeof(TeachingAssistant): " << sizeof(TeachingAssistant) << " bytes." << endl;
	cout << "\tname: " << ta.getName() << endl;
	cout << "\taddress: " << ta.getAddress() << endl;
	cout << "\tsalary: " << ta.getSalary() << endl;
	cout << "\tcourse: " << ta.getCourse() << endl;
	return 0;
}

