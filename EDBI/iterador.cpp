#include <iostream>
#include <iterator>
#include <cassert>
#include <algorithm>

template <typename T>
class MyBidirectionalIterator
{
public:
	using self_type = MyBidirectionalIterator;
	using value_type = T;
	using pointer = T *;
	using reference = T &;
	using difference_type  = std::ptrdiff_t; 
	using iterator_category = std::bidirectional_iterator_tag; //iterator category

private:
	T * m_ptr;

public:
	MyBidirectionalIterator( T * ptr_ = nullptr )
		: m_ptr ( ptr_ )
		{ /*empty*/ }

	~MyBidirectionalIterator() = default;
	MyBidirectionalIterator( const self_type & ) = default;
	self_type & operator=( const self_type & ) = default;

	// *it
	reference operator*()
	{
		assert( m_ptr != nullptr );
		return *m_ptr;

	}

	// ++it
	self_type operator++()
	{
		m_ptr++;
		return *this;
	}

	// it++
	self_type operator++(int)
	{
		self_type temp = *this;
		m_ptr++;
		return temp;
	}

	// it--
	self_type operator--()
	{
		m_ptr--;
		return *this;
	}

	// --it
	self_type operator-- (int)
	{
		self_type temp = *this;
		m_ptr--;
		return temp;
	}

	// it == it2
	bool operator== (const self_type & rhs_ )
	{
		return m_ptr == rhs_.m_ptr;
	}

	//it != it2
	bool operator!= (const self_type & rhs_ )
	{
		return m_ptr != rhs_.m_ptr;
	}


};

class VectorInt 
{
public:
	using iterator = MyBidirectionalIterator<int>;
	using const_iterator = MyBidirectionalIterator< const int >;

private:
	size_t m_len;
	size_t m_capacity;
	int * m_data;

public:
	VectorInt ( size_t sz_=0 )
		: m_len(0)
		, m_capacity(sz_)
		, m_data(new int[sz_] )
		{}

	~VectorInt (void)
	{
		delete [] m_data;
	}

	iterator begin ( void ) const 
	{ return iterator( &m_data[0] ); }

	iterator end ( void ) const 
	{ return iterator( &m_data[m_len] ); }

	const_iterator cbegin ( void ) const 
	{ return const_iterator( &m_data[0] ); }

	const_iterator cend ( void ) const 
	{ return const_iterator( &m_data[m_len] ); }

	bool full( void ) const { return m_capacity == m_len; }

	void reserve ( size_t new_cap )
	{
		if ( new_cap <= m_capacity ) return;

		int * temp = new int[new_cap];
		for( auto i(0ul); i < m_capacity; ++i)
			temp[i] = m_data[i];

		delete [] m_data;

		m_data = temp;

		m_capacity = new_cap;
	}

	void push_back ( int e_ )
	{
		if ( full() )
			reserve( 2 * m_capacity );

		m_data[m_len++] = e_;
	}

};

int main (void)
{
	VectorInt v(10);
	VectorInt::iterator it = v.begin();

	for ( auto i(0); i < 10; ++i )
		v.push_back( i+1 );

	std::cout << ">>> begin() = " << *it << "\n";
	std::cout << ">>> Array: ";
	std::copy ( v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " ") );

	return 0;
}