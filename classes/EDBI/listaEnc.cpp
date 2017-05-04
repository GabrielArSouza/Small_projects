#include <iostream>
#include <cassert>
struct Node
{
	int data; //<! informação armazenado no nó
	Node * next; //<! endereço do próximo elemento

	Node( int v_ =0, Node *n_=nullptr) :data(v_), next(n_)
	{
		/*empty*/
	}
};

//construir lista com 3 nós
Node * build123()
{
	//<! variáveis locais
	Node *first, *second, *third;

	//criando o primeiro nó
	first = new Node(1, nullptr);
	// first = new Node;
	// first->data = 1; 
	// first->next = nullptr;

	//criando o segundo nó
	second = new Node;
	second->data = 2; 
	second->next = nullptr;

	//criando o terceiro nó
	third = new Node;
	third->data = 3;
	third->next = nullptr;

	//conectando o 1ro no 2nd
	first->next = second;
	second->next = third;

	//retorna o inicio da lista
	return first;

}

void print ( const Node * head_ )
{
	const Node *work ( head_ );
	
	std::cout << "[ ";
	while ( work != nullptr )
	{
		//Mostra o conteudo
		std::cout << work->data << " ";
		//avançar para o próximo nó.
		work = work->next;
	}
	std::cout << "]\n";
}

size_t count( const Node * h )
{
	const Node *work ( h );
	size_t cont = 0;
	while ( work != nullptr )
	{
		cont++;
		work = work->next;

	}
	return cont;
}

int main ()
{
	Node * head (nullptr); //criando uma lista vazia
	head = build123();
	print(head);

	Node * empty(nullptr);
	print( empty );

	size_t len = count(head);
	assert( len == 3 );
	return 0;
}