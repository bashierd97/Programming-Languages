// BASHIER DAHMAN 
// A Point Class
// This program determines the distance between two points
// from the origin

#include <iostream>
#include "Point.cpp"



using namespace std;



int main() {

	// initalizing my x and y coordinate variables
	float x;
	float y;

	float x1;
	float y1;

	// prompting the user for an X and Y coordinate to calculate the distance
	cout << "Please enter an X coordinate for the first point: ";
	cin >> x;

	cout << "Now please enter a Y coordinate for the first point: ";
	cin >> y;

	// creating a Point object with the X and Y coordinates
	Point p1(x,y);

	// prompting the user for an X and Y coordinate to calculate the distance
	cout << "Please enter an X coordinate for the second point: ";
	cin >> x1;

	cout << "Now please enter a Y coordinate for the second point: ";
	cin >> y1;

	// creating a Point object with the X and Y coordinates
	Point p2(x1, y1);

	//creating a 3rd point as mentioned by the TA that would have the same coordinates as the first point
	Point p3(x, y);


	// displaying distance from origin to user
	cout << "\nThe coordinates (" << x << "," << y << ") have a distance of " 
		<< p1.distance() << " from the origin\n";


	cout << "The coordinates (" << x1 << "," << y1 << ") have a distance of "
		<< p2.distance() << " from the origin\n";


	int selection = 0;

	// creating a menu for the user so they can choose what to find out about their points
	while (selection != 7){
	cout << "\n\n=====================================================================================================================\n\n";
	cout << "\n\nPlease select from the following options to find out the comparisons between your two points (Number's Only): \n\n";

	cout << "1. Check if the point's have an equal distance from origin\n";
	cout << "2. Check if the point's don't have an equal distance from origin\n";
	cout << "3. Check if Point 1's distance to origin is less than Point 2's\n";
	cout << "4. Check if Point 1's distance to origin is greater than Point 2's\n";
	cout << "5. Check if Point 1's distance to origin is less than or equal to Point 2's\n";
	cout << "6. Check if Point 1's distance to origin is greater than or equal to Point 2's\n";
	cout << "7. QUIT\n";
	cout << "\n\n=====================================================================================================================\n\n";


	// taking input from the user
	cin >> selection;

	// creating a switch case depending on whatever the user selected 
	switch (selection) {

	case 1:
		if (p3 == p2)
			std::cout << "\nTRUE, Point one's distance to origin is EQUAL to Point 2's distance\n";
		else
			std::cout << "\nFALSE, Point one's distance to origin is NOT EQUAL to Point 2\n";
		continue;

	case 2:
		if (p3 != p2)
			std::cout << "\nTRUE, Point one's distance to origin is NOT EQUAL to Point 2\n";
		else
			std::cout << "\nFALSE, Point one's distance to origin is EQUAL to Point 2\n";
		continue;

	case 3:
		if (p1 < p2)
			std::cout << "\nTRUE, Point one's distance to origin is LESS THAN Point 2\n";
		else
			std::cout << "FALSE";
		continue;

	case 4:
		if (p1 > p2)
			std::cout << "\nTRUE, Point one's distance to origin is GREATER THAN Point 2\n";
		else
			std::cout << "FALSE";
		continue;

	case 5:
		if (p1 <= p2)
			std::cout << "\nTRUE, Point one's distance to origin is LESS THAN OR EQUAL to Point 2\n";
		else
			std::cout << "FALSE";
		continue;

	case 6:
		if (p1 >= p2)
			std::cout << "\nTRUE, Point one's distance to origin is GREATER THAN OR EQUAL to Point 2's distance\n";
		else
			std::cout << "FALSE";
		continue;

	}
	}
	//prompt the user to exit the program
	cin.get();


	return 0;
}