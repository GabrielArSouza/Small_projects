#include "cod.h"

int main ()
{

	{
		int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		std::cout << ">>> Procurando o elemento: 4"  << std::endl;
		bool res = binary_search(std::begin(A), std::end(A), 4 );
		if ( res ) std::cout << ">>>Elemento encontrado! :)\n";
		else std::cout << "Elemento NÃO encontrado! :(\n";
	}

	return EXIT_SUCCESS;
}