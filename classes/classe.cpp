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

