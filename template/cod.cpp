#include <iterator>

template <typename T>
bool
binary_search( T * first, T * last, T target )
{

	T * f = first;
	T * l = last;

	T * m;
	
	while ( f < l )
	{
		auto d = std::distance(f, l);
		auto t = d/sizeof(T);
		m = f + t;

		if ( *m == target ) return true;
		else if ( *m > target ) l = m - 1;
		else f = m + 1;

	}

	return false;;

}
