/* calculate area and perimeter of a circle given its radius */
#include <iostream>

using namespace std;

class Circle {
    
    private:
    	float radius, area, perimeter;
   		const float pi = 3.1415;

		float calculateArea(float radius) {
			area = pi * radius * radius;
			return area;
		}
		float calculatePerimeter(float radius) {
			perimeter = 2 * pi * radius;
			return perimeter;
		}
		
	public:
		void setRadius(float r) {
			if (r > 0) {
				radius = r;
			}
			else {
			    cout << "You entered a non-numuric or a negative value. Not cool! \nRadius has been set to a default value of 1" << endl;
			    radius = 1;
			}
			
		}

		float getArea() {
		    area = calculateArea(radius);
			return area;
		}
		
		float getPerimeter() {
			perimeter = calculatePerimeter(radius);
			return perimeter;
		}

		void printResults() {
			cout << "You wanted the perimeter and area of a circle with radius " << radius << endl;
			area = getArea();
			cout << "Area is " << area << endl;
			perimeter = getPerimeter();
			cout << "Perimeter is " << perimeter << endl;
		}
};

int main() {

	float radius, area, perimeter;
	// create circle instance 
    Circle myCircle;
	

	// ask the user for radius
	cout << "Enter radius of a circle to get its area and perimeter: \n";
	cin >> radius;
	myCircle.setRadius(radius);

	// get the results and print them out
	myCircle.printResults();

	return 0;
}
