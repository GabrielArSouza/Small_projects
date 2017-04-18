#include <iostream>
#include "classe.h"

int main () 
{
	Point3d point;
	point.setvalues(1.0, 2.0, 3.0);

	point.print();
	std::cout << std::endl;

	return 0;
}