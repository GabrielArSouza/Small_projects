#include <iostream>
#include <string>
#include <cstring> // memcpy()

using byte = unsigned char;
//typedef unsigned char byte;

//generic
void swap(void *a, void *b, size_t size)
{
	byte aux[size];
	memcpy(aux, a, size ); //equivalente a aux = *a;
	memcpy(a, b, size ); //equivalente a *a = *b;
	memcpy(b, aux, size ); //equivalente a *b = aux;
}

int main ()
{
	int a(5), b(8);
	std::string s("cinco"), t("oito");
	
	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(&a, &b, sizeof(a));
	std::cout << "a: " << a << " b: " << b << std::endl;

	std::cout << "s: " << s << " t: " << t << std::endl;
	swap(&s, &t, sizeof(s));
	std::cout << "s: " << s << " t: " << t << std::endl;

	return EXIT_SUCCESS;
}