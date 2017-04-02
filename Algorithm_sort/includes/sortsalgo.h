#ifndef _SORTSALGO_H_
#define _SORTSALGO_H_

	int compare (int a, int b);
	void insertion_sort (int A[], int len);
	void array_insert (int A[], int & len, int N, int new_element);
	void selection_sort (int V[], int len);
	void bubble_sort (int A[], int len);
	int *partition(int *first, int *last);
	void quick_sort (int *first, int *last);
	void quick_sort_controller (int A[], int len);

#endif