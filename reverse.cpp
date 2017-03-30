#include <iostream>
#include <cstring> // memcpy()

using byte = unsigned char; // byte a byte

void print (int *f, int *l)
{
	std::cout << "[ ";
	while ( f != l)
		std::cout << *f++ << " ";
	std::cout << "]\n";
}


void reverse (void *first, void *last, size_t size)
{
	//converter para byte para permitir aritmetica de ponteiros
	byte *f = (byte *) first; 
	byte *l = (byte *) last;

	//variavel auxilia para viabilizar as cópias
	byte aux[size];

	size_t n = (l - f)/size;
	auto offset(0ul);
	for (auto i(0ul); i < n/2; ++i)
	{
		memcpy( aux, f+(i*size), size); //aux = V[i];
		memcpy( f+offset, f+(n-i-1)*size, size); // v[i] = V[n-i-1+]
		memcpy( f+(n-i-1)*size, aux, size);// V[n-i-1] = aux
		offset +=size;
	}

	std::cout << ">>> " << n << std::endl;
}


int main (){
	int V[] = {1, 2, 3, 4, 5};

	print(std::begin(V), std::end(V));
	reverse(std::begin(V), std::end(V), sizeof(int));
	print(std::begin(V), std::end(V));

	return EXIT_SUCCESS;
}