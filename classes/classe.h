#ifndef _POINT3D_H_
#define _POINT3D_H_

#include <iostream>

class Point3d 
{
	private:
		float m_x;
		float m_y;
		float m_z;

	public:
		void setvalues ( float x, float y, float z );		

		void print ( void ) const;	

		bool isEqual ( const Point3d &p2 ) const;	

		bool operator==(const Point3d & ) const;

};

#endif