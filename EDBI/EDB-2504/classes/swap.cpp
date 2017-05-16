#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T>

T myMax( T * first, T* last){

	T maior = *first++;

	while( first != last){

		if(*first > maior){
			maior = *first;
		}
		first++;
	}

	return maior;

}
template <typename T1>
void swap( T1 &a, T1 &b){

	T1 aux;

	aux = a;
	a = b;
	b = aux;
}
template <typename T2>
T2 * iterative_binary_search (T2 *first, T2 *last, T2 key) {
    int indice;


    while (first < last ) {
        indice = std::distance(first, last) / 2;

        if (*(first + indice) == key) {

            return first+indice;
        }

        else if (*(first + indice) < key) {

            first = first + indice + 1;
        } else {

            last = first + indice - 1;
        }
    }
    return last;
}

int main(){

	int a = 0;
	int b = 100;

	std::string A[] = { "um", "dois", "tres"};
	int B[] = {1, 2, 3, 5, 7, 8, 9};

	swap(a, b);


	std::copy(std::begin(B), std::end(B), std::ostream_iterator< int >(std::cout, " "));
	std::cout << std::endl << myMax(std::begin(B), std::end(B)) << std::endl;

	std::copy(std::begin(A), std::end(A), std::ostream_iterator< std::string >(std::cout, " "));
	std::cout << std::endl << myMax(std::begin(A), std::end(A)) << std::endl;

	std::cout << a << " e " << b << std::endl;

	auto result = iterative_binary_search(std::begin(B), std::end(B), 3);

	if(result != std::end(B)){
		std::cout << ">>>Element " << *result << " found at position " << std::distance( std::begin(B), result) << std::endl;
	}else{
		std::cout << ">>>Not found" << std::endl;
	}
	
	result = iterative_binary_search(std::begin(B), std::end(B), 5);

	if(result != std::end(B)){
		std::cout << ">>>Element " << *result << " found at position " << std::distance( std::begin(B), result) << std::endl;
	} else{
		std::cout << ">>>Not found" << std::endl;
	}

	result = iterative_binary_search(std::begin(B), std::end(B), -1);

	if(result != std::end(B)){
		std::cout << ">>>Element " << *result << " found at position " << std::distance( std::begin(B), result) << std::endl;
	} else{
		std::cout << ">>>Not found" << std::endl;
	}

	return 0;
}
