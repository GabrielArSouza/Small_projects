#include <iostream>
#include "point.h"

int main(){

	Point3d point;
	point.setValues(1.0, 2.0, 3.0);

	point.print();
	std::cout << std::endl;
	return 0;
}