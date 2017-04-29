
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <iterator>

namespace ls{
	template <typename T>
	class Vector{

		private:

			//!< Default size for the vector
			static constexpr std::size_t DEFAULT_SIZE{ 0 };

			T *m_data;       //!< Dynamic storage area
			std::size_t m_len; //!< Logical length.
			std::size_t m_size;//!< Size of the array.

		public:

			//!<Default constructor
			Vector(std::size_t size = DEFAULT_SIZE)
			: m_data(new T[size + 1]) // +1 é necessário para a posição extra do end().
			, m_len(0)
			, m_size(size)
			{
				/*empty*/
			}

			~Vector( ){
				delete [] m_data;
			}

			//!< Return number of elements of array
			std::size_t size() const{

				return m_len;
			}

			//!< Returns true is vector has no elements
			bool empty ()const{

				return (m_len == 0);
			}

			//!< Returns true if vector is full
			bool full ()const{

				return (m_len == m_size);
			}

			//!< Inserts element at the end of the array
			void push_back(const T & value){

				if(full())
				{
					resize( 2 * m_size );
					throw std::length_error("[push_back()]: vector is full");
				}

				m_data[m_len++] = value;

			}
			void push_front(T value){}
			T pop_back(){

				if(empty())
					throw std::out_of_range("[pop_back()] Cannot recover element from an empty vector.");

				return m_data[--m_len];

			}
			void pop_front(){}

			//!< Returns first element of the array
			T front() const{

				if(empty())
					throw std::out_of_range("[front()] Cannot recover element from an empty vector.");

				return m_data[0];
			}

			//!< Returns last element of the array
			T back(){
				if(empty())
					throw std::out_of_range("[back()] Cannot recover element from an empty vector.");

				return m_data[m_len-1];
			}

			//!< Return the actual size of array
			std::size_t capacity() const {

				return m_size;
			}

			//!< Clear vector 
			void clear(){
				m_len = 0;
			}

			void print( ) const{

				std::cout << ">>> [";
				std::copy( &m_data[0], &m_data[m_len], std::ostream_iterator<int>(std::cout, " "));

				std::cout << "], len=" << m_len << ", capacity=" << m_size <<".\n"; 
			}
	};
}

int main(){

	ls::Vector <int> v(100);
	std::cout << "Size: " << v.size() << std::endl;

	ls::Vector <int> v2;
	std::cout << "Size: " << v2.size() << std::endl;


	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.print();
	v.pop_back();
	v.pop_back();
	v.print();

	try{
		std::cout << v.front() << std::endl;
	}
	catch(const std::out_of_range &e){
		
		std::cout << ">> Error: " << e.what() << std::endl;
	}
	try{
		std::cout << v2.front() << std::endl;
	}
	catch(const std::out_of_range &e){
		
		std::cout << ">> Error: " << e.what() << std::endl;
	}

	assert(v.empty() == false);

	return 0;
}