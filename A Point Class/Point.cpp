// BASHIER DAHMAN 
// Point.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;

class Point
{
private:
	float x, y;
	float point_distance = distance();

public:
	
	Point(float x3, float y3) : x{ x3 }, y{ y3 }
	{
	}

	float distance() {
		// Calculating distance 
		return sqrt(pow(x - 0, 2) + pow(y - 0, 2) * 1.0f);
	}
	
	// my friend function for less than operator
	friend bool operator< (const Point& lhs, const Point& rhs);
};

// overriding less than operator 
inline bool operator< (const Point& lhs, const Point& rhs)
{
	return (lhs.point_distance < rhs.point_distance);
}
// overriding greater than operator
inline bool operator> (const Point& lhs, const Point& rhs) { 
	return  operator< (rhs, lhs); 
}

// overriding less than or equal to operator 
inline bool operator<= (const Point& lhs, const Point& rhs) { 
	return !operator> (lhs, rhs); 
}

// overriding greater than or equal to operator 
inline bool operator>= (const Point& lhs, const Point& rhs) { 
	return !operator< (lhs, rhs); 
}

// overriding equals to operator
inline bool operator== (const Point& lhs, const Point& rhs) {
	return !operator<(lhs, rhs) && !operator>(lhs, rhs);
}

// overriding not equals operator
inline bool operator!= (const Point& lhs, const Point& rhs) {
	return !operator==(lhs, rhs);
}