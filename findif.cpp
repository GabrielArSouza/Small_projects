#include <iostream>
#include <functional>
#include <iterator>

using byte = unsigned char; // byte a byte

bool maior_5 ( const void *e )
{
	const int *i = (const int *) e;
	return *i > 5;
}


bool eh_par ( const void *e )
{
	const int *i = (const int *) e;
	return (*i % 2) == 0;
}

void * find_if ( const void * first, const void * last,
				size_t size, 
				std::function<bool(const void *) >p )
{
	const byte *f = (const byte *) first;
	const byte *l = (const byte *) last;

	for (; f != l; f += size)
	{
		if (p(f)) return (void *) f;
	} 

	return (void *) f; //se chegar aqui é pq não encontrou
}

int main (){
	int V[] = {1, 1, 3, 4, 5, 6, 7, 8};

	int *result = (int *) find_if( std::begin(V), std::end(V), sizeof(int), eh_par);

	std::cout << ">>> Result= " << *result << std::endl;
	std::cout << "	Na posição = " << std::distance( std::begin(V), result);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}