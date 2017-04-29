#include "classe.h"

void Point3d::setvalues ( float x, float y, float z )
{
	m_x = x; //this->m_x = x
	m_y = y;
	m_z = z;
}

void Point3d::print ( void ) const
{
	std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">"; 
}

bool Point3d::operator==(const Point3d &p2 ) const
{
	return (m_x == p2.m_x and m_y == p2.m_y and m_z == p2.m_y);
}
bool Point3d::isEqual ( const Point3d &p2 ) const
{
	return (m_x == p2.m_x and m_y == p2.m_y and m_z == p2.m_y);
}
