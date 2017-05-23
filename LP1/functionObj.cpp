#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

bool above_3( int val_ )
{
	return val_ > 3;
}

class Above
{

private:
	int limite;

public:
	Above( int l_=0 ) : limite( l_ )
	{ /*empty*/ } 
	bool operator() ( int val_ ) 
	{
		return val_ > limite;
	}
};

//
#define TEMPLATE
//
#ifdef FUNCTION_PTR
template < typename FwrdIt >
std::vector<int>
find_matching_numbers ( FwrdIt first, FwrdIt last, bool ( *pred_ )( int ) ) 
#endif
#ifdef FUNCTIONAL
template < typename FwrdIt >
std::vector<int>
find_matching_numbers ( FwrdIt first, FwrdIt last, std::function< bool( int ) > pred_ ) 
#endif
#ifdef TEMPLATE
template < typename FwrdIt, typename UnaryPredicate >
std::vector<int>
find_matching_numbers ( FwrdIt first, FwrdIt last, UnaryPredicate pred_ ) 
#endif
{
	std::vector<int> selected;

	while( first != last )
	{
		if ( pred_( *first ) == true )
		{
			selected.push_back( *first );
		}
		first++;
	}

	return selected;
}


int main ()
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	std::cout << ">>> Original array: [ ";
	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " ") );
	std::cout << "]\n";

	//criar um subconjunto da coleção que satisfaz uma certa condição
	//auto result = find_matching_numbers( v.begin(), v.end(), above_3 );
	Above acima(2);
	auto result = find_matching_numbers( v.begin(), v.end(), acima );

	std::cout << ">>> selected array: [ ";
	std::copy( result.begin(), result.end(), std::ostream_iterator<int>( std::cout, " ") );
	std::cout << "]\n";

	std::cout << ">>> Normal exiting...\n";
	return 0;
}