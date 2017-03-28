#include <iostream>
#include <sstream>
#include <random>
#include <iterator>
#include <algorithm>

#include "../includes/sortsalgo.h"

using SortFuncType = void (*) (int *, int);

void print( int A[], size_t len )
{
    std::cout << ">>> A[ ";
    for( auto i(0u) ; i < len ; ++i )
        std::cout << A[i] << " ";
    std::cout << "], tamanho = " << len << "\n";
}

int main (int argc, char *argv[])
{
	//por padrão usa-se a ordenação por inserção
	auto TypeFunc(0);

	//ponteiros para as funções
	SortFuncType SortsAlgo[]{
		//insertion_sort,
		selection_sort,
		bubble_sort
	};

	//Informações de erro e atribuição de variáveis
	if (argc < 2)
	{
		std::cout << "\tDesculpe..." << std::endl;
		std::cout << "\tErro de Sintaxe" << std::endl;
		std::cout << "Por favor, execute da forma:" << std::endl;
		std::cout << ">>> ./bin [f]"<< std::endl;
		std::cout << std::endl;
		std::cout << "[f]:" << std::endl;
		std::cout << "0 - Selection sort" << std::endl;
		std::cout << "1 - Bubble sort" << std::endl;

		return EXIT_FAILURE;
	}else {
		std::stringstream(argv[1]) >> TypeFunc;
	}

	// Vetor de teste.
    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::random_device rd;
    std::mt19937 g(rd());

    // Embaralhar o vetor.
    std::shuffle( std::begin(A), std::end(A), g );

    int len = 10; // tamanho logico

    std::cout << "Vetor original\n";
    print(A, len);

    (SortsAlgo[TypeFunc])( A, len);

    std::cout << "Vetor ordenado\n";
    print(A, len);

    return EXIT_SUCCESS;
}