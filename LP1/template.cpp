#include <iostream>

template < typename T >
void DoubleArray ( T * &A_ , size_t & size_ )
{
	// (1) Alocar nova memória
	T * temp = new T[ size_ * 2 ];

	// (2) Copiar valores de A para o novo vetor
	for ( auto i(0u); i < size_; ++i)
	{
		//*(temp+i) = *(A_+i); 
		temp[i] = A_[i];
	}

	// (3) Liberar a memória associada ao ponteiro A
	delete [] A_;

	// (4) Fazer o A apontar p/ a nova memória
	A_ = temp;

	// (5) Atualizar o novo tamanho do arranjo A;
	size_ *= 2;
}

int main ()
{
	size_t nReadElements = 0;
	int *vpiArrlen;
	size_t viArrlen = 5;

	int x;

	// try {
	// 	vpiArrlen = new int [ viArrlen ];
	// }
	// catch ( bad_alloc exception ) {
	// 	cerr << "\n [main()] error \n";
	// }

	std::cout << ">>> Enter items: " << std::endl;
	while ( std::cin >> x ){

		if ( ++nReadElements >= viArrlen) 
		{
			std::cout << ">>> Dobrando o espaço..." << viArrlen << " para ";
			DoubleArray (vpiArrlen, viArrlen );
			std::cout << ">>> Novo tamanho: " << viArrlen << std::endl;
		}

		vpiArrlen[ --nReadElements ] = x;

	}

	return 0;
}