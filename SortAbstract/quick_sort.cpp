#include <iostream>
#include <functional>

void print (int *first, int *last)
{
	std::cout << "[ ";
	for (/*empty*/; first < last; ++first)
	{
		std::cout << *first << " ";
	}
	std::cout << "]";
}

int * partition (int * first, int *last)
{
	auto pivot = *(last-1); // ultimo elemento valido.
	auto slow( first );
	auto fast( first );

	while ( fast != last)
	{	
		if (*fast <= pivot){
			std::swap(*fast, *slow);
			slow++;
		}

		fast++;
	}
	return slow;
}

void quick_sort ( int * first, int * last)
{
	//caso base
	if (first == last) return; 

	auto past_pivot = partition ( first, last);

	quick_sort (first, past_pivot-1);
	quick_sort (past_pivot, last);
	
}

int main ( void )
{
	int A1[] = {7, 10, 1, 3, 6, 8, 2, 9, 4, 5};
	int A2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int A3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	// std::cout << ">>> Antes da partição:\n";
	// print(std::begin(A1), std::end(A1) );
	// std::cout << std::endl;

	// auto past_the_pivot = partition (std::begin(A1), std::end(A1) );
	// auto pivot = past_the_pivot-1; 

	// print(std::begin(A1), pivot); //Imprime a primeira parte do arranjo particionado
	// std::cout << " " << *pivot << " "; //imprime o pivô
	// print(past_the_pivot, std::end(A1)); // imprime a segunda parte do arranjo (>pivot)
	// std::cout << std::endl;

	std::cout << ">>> Antes da partição:\n";
	print(std::begin(A1), std::end(A1) );
	std::cout << std::endl;

	quick_sort( std::begin(A1), std::end(A1));

	std::cout << ">>> Depois da partição:\n";
	print(std::begin(A1), std::end(A1) );
	std::cout << std::endl;

	return EXIT_SUCCESS;
}