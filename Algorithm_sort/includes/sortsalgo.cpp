#include <iterator>

int compare (int a, int b)
{
	if ( a == b ) return 0;
	else if (a < b ) return -1;
	else return 1;
}

void array_insert (int A[], int & len, int N, int new_element)
{
	if (len == N) //TamLógico == TamFísico (vetor cheio)
	   return;

	auto i(len-1);
	while (i >= 0 and new_element < A[i])
	{
		//abrir espaço
		A[i+1] = A[i];
		i--; //caminhar até o começo
	}
	A[i+1] = new_element;
	//atualizar tamanho lógico
	len++;
}

void insertion_sort (int A[], int len)
{
	auto tam_logico_ord(1);
	for (auto i(1); i < len; ++i)
	{
		auto target(A[i]);
		array_insert(A, tam_logico_ord, len, target);
	}
}

void selection_sort (int A[], int len)
{
	for (auto i(0); i < len-1; ++i)
	{
		auto menor(i);
		for (auto j(i+1); j < len; ++j )
		{
			if (compare( A[j], A[menor]) == -1)
				menor = j;
		}
		std::swap(A[i], A[menor]);
	}
}

void bubble_sort (int A[], int len)
{
	auto troca = true;
	
	while ( troca )
	{
		troca = false;
		for (auto i(0); i < len-1; ++i)
		{
			if ( compare(A[i], A[i+1]) == 1){
				std::swap(A[i], A[i+1]);
				troca = true;
			}
		}
	}
}

int *partition(int *first, int *last)
{
	auto pivot = *(last - 1);
	auto slow(first);
	auto fast(first);

	for (/*empty*/; fast != last; ++fast)
	{
		if (*fast <= pivot)
		{
			std::swap(*fast, *slow);
			slow++;
		}
	}
	return slow;
}

void quick_sort (int *first, int *last)
{
	//caso base
	if ( first == last) return;

	auto past_pivot = partition(first, last);

	quick_sort(first, past_pivot-1);
	quick_sort(past_pivot, last);
}

void quick_sort_controller (int A[], int len)
{
	int *first = &A[0];
	int *last = &A[len];

	quick_sort(first, last);
}