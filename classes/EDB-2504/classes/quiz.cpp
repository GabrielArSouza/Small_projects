#include <iostream>
#include <cmath>

//Question 1
class Point2d{

    private:
        float m_x;
        float m_y;

    public:

        //Constructor
        Point2d(float x=0.0, float y=0.0)
        : m_x(x), m_y(y)
        { /*empty*/ }

        void print(){
            std::cout << "Point2d(" << m_x << ", " << m_y << "); " << std::endl; 
        }

        float distanceTo(const Point2d &p2){
            float distance = (m_x - p2.m_x) * (m_x - p2.m_x) + 
                             (m_y - p2.m_y) * (m_y - p2.m_y);
                    
            return sqrt(distance);
        }

        friend double distanceFrom(Point2d x, Point2d y);
};

//Non-member function
double distanceFrom(Point2d x, Point2d y){

   return sqrt((x.m_x - y.m_x) * (x.m_x - y.m_x) + 
                (x.m_y - y.m_y) * (x.m_y - y.m_y));
                    
}

class HelloWorld
{
private:
	char *m_data;
 
public:
	HelloWorld()
	{

        m_data = new char[14]{ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' };
 

	}
 
	~HelloWorld()
	{
        // replace this comment with your destructor implementation
        std::cout << "\n>>>Deleted!\n";
        delete [] m_data;
	}
 
	void print()
	{
		std::cout << m_data;
	}
 
};

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
 
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    HelloWorld hello;
	hello.print();

    return 0;
}