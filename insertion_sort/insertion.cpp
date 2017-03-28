#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

/*!
 * Insere um elemento em um vetor já ordenada mas que ainda tem espaço.
 * \note Se o vetor estiver cheio, a função não faz nada.
 *
 * \param A Vetor onde o novo slemento será inserido.
 * \param len Referência para o tamanho lógico do vetor.
 * \param N Tamanho físico do vetor.
 * \param new_element Novo elemento a ser inserido no vetor.
 */
void sorted_array_insert( int A[], int & len, int N, int new_element )
{
    if ( len == N ) return; // Vetor já está cheio, tamanho lógico == tamanho físico.

    auto i(len-1); // Começamos do último elemento válido.
    while( i >= 0 and new_element < A[i]  )
    {
        // Abrir espaco
        A[i+1] = A[i];
        i--; // Caminhar até o começo do vetor
    }
    // Incluir o novo elemento.
    A[i+1 ] = new_element;

    // Atualizar o tamanho logico.
    len++;
}

/*!
 * Imprime o conteúdo do vetor na saída padrão.
 * \param A Vetor a ser impresso.
 * \param Comprimento do vetor a ser impresso.
 */
void print( int A[], size_t len )
{
    std::cout << ">>> A[ ";
    for( auto i(0u) ; i < len ; ++i )
        std::cout << A[i] << " ";
    std::cout << "], tamanho = " << len << "\n";
}

/*!
 * Algoritmo de ordenação, versão inicial.
 * \note Esta função utiliza a função sorted_array_insert para
 * ordenar.
 *
 * \param A Vetor a ser ordenado.
 * \param len Tamanho do vetor.
 */
void insertion_sort( int A[], int len )
{

    auto tamanho_logico_subvetor_ordenado(1);
    for( auto i(1) ;  i < len ; ++i )
    {
        auto target( A[i] );
        sorted_array_insert( A, tamanho_logico_subvetor_ordenado, len, target );
    }

}


void selection_sort (int A[], int len)
{
	for (auto j(0); j < len-1; ++j){

		auto menor(j);
		for (auto i(j+1); i < len; ++i)
		{
			if (A[i] < A[menor])
			{
				menor = i;
			}
		}
		std::swap(A[j], A[menor]);
	}
}

int compara( int a, int b)
{
	return b-a;
}

void bubble_sort (int A[], int len, int (*compara) (int, int))
{
	bool troca = true;

	while (troca)
	{
		troca = false;
		for (auto i(0); i < len-1; ++i)
		{
			if (compara(A[i], A[i+1]) < 0)
			{
				std::swap(A[i], A[i+1]);
				troca = true;
			}
		}
	}

}

int main()
{
    // Vetor de teste.
    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::random_device rd;
    std::mt19937 g(rd());

    // Embaralhar o vetor.
    std::shuffle( std::begin(A), std::end(A), g );

    int len = 10; // tamanho logico

    std::cout << "Vetor original\n";
    print(A, len);

    bubble_sort( A, len, compara);

    std::cout << "Vetor ordenado\n";
    print(A, len);


    return 0;
}
