#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <functional>
// Functor que multiplica por 10 se par, por 20 se impar
struct Multiplicator
{

private:
	int factor;

public:
	Multiplicator (const int value ) :factor(value) {}

	int operator()(const int & value_ )
	{
		return value_ * factor;
	}
};

int main ()
{
	std::vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << ">>> array: [ ";
	std::copy ( a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " " ) );
	std::cout << "]\n";

	// o '=' dentro dos [] captura todas as variáveis do escopo
	auto func =
	 	[a] // lista de captura
	 	( int i ) -> bool
	 	{ 
	 		std::cout << "Hello world!\n"; 
	 		std::cout << "Parameter = " << i << std::endl;
	 		std::cout << "Size of vector is: " << a.size() << std::endl;
	 		return true;
	 	};

	func( 10 );

	//Multiplicar todos os elementos por 10 com transform
	Multiplicator xx(5); //cria objeto
	std::transform( a.begin(), a.end(), a.begin(), xx );

	std::cout << ">>> transform: [ ";
	std::copy ( a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " " ) );
	std::cout << "]\n";

	std::cout << "\n\n>>> Normal exiting\n";
	return 0;
}