/* Instruction: Read all the comments and complete the code by defining all the methods. 
   Do not forget to add Destructor where it is necessary.
   Feel free to add more methods (as per your thoughts/requirement)
*/

#include <iostream>
#include <math.h>

using namespace std;


//############################Point#######################################

class Point{
	public:
		double x;
		double y;
		// Public constructor
		Point();
		Point(const Point &p);
		Point(double x_val, double y_val);

		//finds distance between two points (between this and Point p2)
		double getDistance(Point p2);
		void translate(double x_val, double y_val);
		void setPosition(double x_val, double y_val);	
};
Point::Point(){
	x = 0.0;
	y = 0.0;
}

Point::Point(const Point &p){
	x = p.x;
	y = p.y;
}

Point::Point(double x_val, double y_val){
	x = x_val;
	y = y_val;
}

double Point::getDistance(Point p2){
	// Using the distance formula
	// sqrt((x1 - x2)^2 + (y1 - y2)^2)

	return sqrt(((x - p2.x) * (x - p2.x)) 
							+ ((y - p2.y) * (y - p2.y)));
}

void Point::translate(double x_val, double y_val){
	x = x + x_val;
	y = y + y_val;
}

void Point::setPosition(double x_val, double y_val){
	x = x_val;
	y = y_val;
}

//############################Shape######################################

class Shape {
		int vertices;
		Point *points;

		friend class Rectangle;
		friend class Triangle;
	public:
		//allocates memory for array points and initializes vertices
		Shape(int vertices);
		// set x and y for all vertices in points
		// new_points must point to an array of points
		void setDim(Point *new_points);
		//will be overridden in derived classes
		virtual void showArea(){
			cout<<"Area of Shape"<<endl;
		};
		//will be overridden in derived classes
		virtual void showPerimeter(){
			cout<<"Permieter of Shape"<<endl;
		};
};

Shape::Shape(int vertices){
	this->vertices = vertices;

	points = new Point[vertices];
}

void Shape::setDim(Point *new_points){
	if(sizeof(*new_points)/sizeof(new_points[0]) > vertices){
		for(int i = 0; i < vertices; i ++){
			points[i] = new_points[i];
		}
	}else{
		cout << "Error: not enough points in given array of points" << endl;
	}
}

//##########################Rectangle#################################

class Rectangle: public Shape{
		double height;
		double width;

	public:
		//declare constructor for Rectangle
		Rectangle(double height, double width);
		//calculate and print the area of the rectangle
		void showArea();
		//calculate and print the permieter of the rectangle
		void showPerimeter();
};

Rectangle::Rectangle(double height_val, double width_val) : Shape(4){
	height = height_val;
	width = width_val;

	points[0].setPosition(0.0,0.0);
	points[1].setPosition(0.0,height);
	points[2].setPosition(width, height);
	points[3].setPosition(width, 0.0);
}

void Rectangle::showArea(){
	cout << "Rectangle Area: " << (height * width) << endl;
}

void Rectangle::showPerimeter(){
	cout << "Rectangle Perimeter: " << (height*2) + (width*2) << endl;
}

//############################Triangle####################################


class Triangle: public Shape{
		//type is 1 for equilateral, 2 for isosceles and 3 for right angled triangle
		int type;
	public:
		//declare constructor for Triangle
		Triangle(double scale, int type);

		Triangle(Point p1, Point p2, Point p3, int type);
		// Check whether the points enetered form a valid triangle based on its type
		// If not, print an appropriate message and exit
		bool validTriangle();
		//calculate and print the area of the traingle
		void showArea();
		//calculate and print the permiter of the triangle
		void showPerimeter();
		//do the necessary calculation and set the type
		void setType(int type);
		//return the type
		int getType() const;
};

Triangle::Triangle(double scale, int type_val) : Shape(3){
	type = type_val;

	switch(type_val){
		case 1:
			points[0].setPosition(-(0.5*scale), 0.0);
			points[1].setPosition(0.0, (0.5*scale));
			points[2].setPosition((0.5*scale), 0.0);
			break;
		case 2:
			points[0].setPosition(-(0.5*scale), 0.0);
			points[1].setPosition(0.0, (scale));
			points[2].setPosition((0.5*scale), 0.0);
			break;
		case 3:
			points[0].setPosition(0.0, 0.0);
			points[1].setPosition(0.0, (scale));
			points[2].setPosition((scale), 0.0);
			break;
	}
}

Triangle::Triangle(Point p1, Point p2, Point p3, int type_val) : Shape(3){
	type = type_val;
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
}

bool Triangle::validTriangle(){
	bool verdict = false;
	double side1 = points[0].getDistance(points[1]);
	double side2 = points[1].getDistance(points[2]);
	double side3 = points[0].getDistance(points[2]);
	switch(type){
		case 1:
			if(side1 == side2 && side1 == side3){
				verdict = true;
			}
			break;
		case 2:
			if(side1 == side2 || side1 == side3 || side2 == side3){
				verdict = true;
			}
			break;
		case 3:
			if(pow(side1,2) + pow(side2,2) == pow(side3,2)
			|| pow(side2,2) + pow(side3,2) == pow(side1,2)
			|| pow(side1,2) + pow(side3,2) == pow(side2,2)){
				verdict = true;
			}
			break;
	}
}

void Triangle::showArea(){
	if(this->validTriangle()){
		double side1 = points[0].getDistance(points[1]);
		double side2 = points[1].getDistance(points[2]);
		double side3 = points[0].getDistance(points[2]);

		cout << "Triangle Area: ";

		switch(type){
			case 1:
				cout << (sqrt(3)/4) * side1;
				break;
			case 2:
				{
					double base = min(min(side1,side2), side3);
					double height;
					if(base == side1){
						height = (sqrt(pow(base/2,2) + pow(side2,2)));
					}else if(base == side2){
						height = (sqrt(pow(base/2,2) + pow(side1,2)));
					}else{
						height = (sqrt(pow(base/2,2) + pow(side2,2)));
					}
					cout << (base * height) / 2;
				}
				break;
			case 3:
				{
					double hypo = max(max(side1,side2), side3);
					if(hypo == side1){
						cout << (side2 * side3) / 2;
					}else if(hypo == side2){
						cout << (side1 * side3) / 2;
					}else{
						cout << (side2 * side1) / 2;
					}
				}
				break;
		}
		cout << endl;
	}
}

void Triangle::showPerimeter(){
	double side1 = points[0].getDistance(points[1]);
	double side2 = points[1].getDistance(points[2]);
	double side3 = points[0].getDistance(points[2]);

	cout << "Triangle perimeter: " << (side1 + side2 + side3) << endl;
}

int Triangle::getType() const{
	return this->type;
}

void Triangle::setType(int type_val){
	double side1 = points[0].getDistance(points[1]);
	double side2 = points[1].getDistance(points[2]);
	double side3 = points[0].getDistance(points[2]);

	if(type_val == 1 || type_val == 2 || type_val == 3){

		//Get the longest side
		double scale = max(max(side1,side2), side3);

		//Get the anchor point of the triangle
		Point offset = points[0];

		//Create a new triangle based on scale and new type
		Triangle target(scale, 2);

		//Set type of triangle
		type = 2;

		//translate back to anchor point
		points[0] = target.points[0];
		points[1] = target.points[1];
		points[2] = target.points[2];

		for(int i = 0; i < vertices; i++){
			points[i].translate(offset.x, offset.y);
		}
	}else{
		cout << "Invalid triangle type: " << type_val 
			 << ", please use (1, 2, 3)" << endl;
	}
}

int main(){
	//create instance of Rectangle and Triangle
	Rectangle rec(1.0, 1.5);
	Triangle tri(2.0, 1);
	//call showArea and showPerimeter for Rectangle 
	rec.showArea();
	rec.showPerimeter();
	//set the type of triangle; also print its area and perimeter (only if the given points make a valid triangle)
	if(tri.validTriangle()){
		tri.showPerimeter();
		tri.showArea();
	}
	return 0;
}
