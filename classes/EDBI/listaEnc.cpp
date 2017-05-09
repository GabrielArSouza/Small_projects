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
//dicas importantes 
bool push_front ( Node * & head_, int value_)
{
	// criar novo nó com o valor
	Node *temp(nullptr);
	try 
	{
		Node *temp = new Node( value_, nullptr);
	}
	catch ( std::bad_alloc & e)
	{
		return false;
	}
	
	// apontar para o primeiro valor da lista
	temp->next = head_;
	//fazer o head apontar para o novo elemento
	head_ = temp;

	return true;
}

void clear ( Node * & head_)
{
	Node * current( head_ );

	while( current != nullptr )
	{
		auto condenado( current );
		current = current->next;
		delete condenado;
	}
}

// int * get_data( const Node * head_, size_t & len_)
// {
// 	//recuperar o tamanho da lista
// 	len_ = length ( head_ );

// 	//alocar 
// 	int * data = new int [];

// 	//atualizar o comprimento do vetor.
// 	len_ =;

// 	//copiar os dados da lista para o vetor 
// 	auto i(0u);
// 	while ( head_ != nullptr )
// 	{
// 		data[i++] = head_->data;
// 		head_ = head_->next;
// 	}
// } 


int main ()
{
	Node * head (nullptr); //criando uma lista vazia
	head = build123();
	print(head);

	Node * empty(nullptr);
	print( empty );

	size_t len = count(head);
	assert( len == 3 );

	// {
	// 	Node * head(nullptr);
	// 	head = build123();

	// 	size_t v1_len;
	// 	//auto v1_data = get_data( head, v1_len);
	// 	// int expected[] = {1, 2, 3};
	// 	// for ( auto i(0); i < v1_len)

	// 	push_front( head, 4);

	// 	Node * head2(nullptr);
	// }


	return 0;
}