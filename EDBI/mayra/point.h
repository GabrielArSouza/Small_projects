#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point3d{
	private:
		float m_x;
		float m_y;
		float m_z;

	public:
		void setValues(float x, float y, float z);

		void print(void) const;	
		bool isEqual(const Point3d &p) const;
};

#endif