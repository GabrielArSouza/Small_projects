#include <iterator>

void selection_sort (int A[], int len)
{
	for (auto i(0); i < len-1; i++)
	{
		auto menor(i);

		for (auto j(i+1); j < len; j++)
		{
			if (A[j] < A[menor]) menor = j;
		}

		std::swap(A[i], A[menor]);

	}
}

void bubble_sort (int A[], int len)
{
	bool troca = true;

	while (troca)
	{
		troca = false;
		for(auto i(0); i < len-1; ++i)
		{
			if (A[i] > A[i+1]){
				std::swap(A[i], A[i+1]);
				troca = true;
			}
		}

	}
}