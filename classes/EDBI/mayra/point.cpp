#include "point.h"


void Point3d::setValues(float x, float y, float z){
	m_x = x;
	m_y = y;
	m_z = z;
}

void Point3d::print(void) const{
	std::cout << " <" << m_x
			  << ", " << m_y
			  << ", " << m_z
			  << "> ";
}	

bool Point3d::isEqual(const Point3d &p) const{

	return (m_x == p.m_x and m_y == p.m_y and m_z == p.m_z);
}