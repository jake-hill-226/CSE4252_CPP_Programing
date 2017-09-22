/**
 * Calculator.cpp
 * Desc: Simple console based calculator
 * 		 --For CSE 4252, Lab1
 * Author: Jake Hill
 * Last Reviewed: 9/15/17 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <limits>

using namespace std;

void printBuffer(int);

int main(){

	double val_1;
	double val_2;
	char op;
	bool valid_input = false;

	printBuffer(80);

	cout << "Welcome to EasyCalc" << endl
		 << "Edumacated Solutions" << endl
		 << "--Copyright (c) 2017--" << endl;

	printBuffer(2);

	cout << "Lets get started!" << endl;
	
	// Application Loop
	do{
		cout << "Choose your op," << endl
			<< "# + : addition" << endl
			<< "# - : subtraction" << endl
			<< "# * : multiplication" << endl
			<< "# / : division" << endl
			<< "# % : modulous" << endl
			<< "(choose 'q' to quit)" << endl;
		
		// Input Loop
		while(!valid_input){
			cout << "Choice? : ";
			cin >> op;

			switch(op){
				case '+' : valid_input = true;
							break;
				case '-' : valid_input = true;
							break;
				case '*' : valid_input = true;
							break;
				case '/' : valid_input = true;
							break;
				case '%' : valid_input = true;
							break;
				case 'q' : valid_input = true;
							break;
				default : cout << op << " is not a valid operator, try again"
								<< endl << endl;
			}

			//Clear out the buffer before accessing the stream again
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		valid_input = false;

		if(op != 'q'){
			cout << "Enter first operand: ";
			cin >> val_1;
			while(cin.fail()){
				if(cin.fail()){
					cout << endl << "Invalid input try again" << endl;
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter first operand: ";
				cin >> val_1;
			}
			//Clear out the buffer before accessing the stream again
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			cout << "Enter second operand: ";
			cin >> val_2;
			
			//Clear out the buffer before accessing the stream again
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printBuffer(80);

			// Catch Division by zero
			if(val_2 == 0 && op == '/'){
				cout << endl << "Cannot divide by 0, try again";
				printBuffer(4);
				continue;
			}

			stringstream result;
			result << val_1 << " " << op << " " << val_2 << " = ";

			// Perform the operation
			// Check for overflow cases 
			switch(op){
				case '+' : if((val_1 + val_2) >= val_1){
								result << (val_1 + val_2);
							}else{
								result.str("Numbers are too large");
							}
							
							break;
				case '-' : if((val_1 - val_2) <= val_1){
								result << (val_1 - val_2);
							}else{
								result.str("Numbers are too large");
							}
							break;
				case '*' : if((val_1 - val_2) >= val_1){
								result << (val_1 - val_2);
							}else{
								result.str("Numbers are too large");
							}
							break;
				case '/' : result << (val_1 / val_2);
							break;
				case '%' : result << fmod(val_1, val_2);
							break;
			}

			cout << endl << result.str();

			printBuffer(4);
		}
		
	}while(op != 'q');

	return 0;
}

// Prints {num_lines} return characters followed
// by a horizontal separator to the stdout buffer
void printBuffer(int num_lines){
	for(int i = 0; i < num_lines; i++){
		cout << endl;
	}
	cout << "--------------------------------------" << endl;
}