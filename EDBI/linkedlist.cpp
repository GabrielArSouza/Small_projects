#include <iostream>
#include <cassert>

struct Node {
	
	int data;
	Node * next;

	Node( int v_=0, Node *n_=nullptr ) : data(v_), next(n_)     
	{ /* empty */ }
};

Node * build123() {
	Node * h, * second, *third;


	h = new Node;
	h->data = 1;
	h->next = nullptr;

	second = new Node;
	second->data = 2;
	second->next = nullptr;

	third = new Node;
	third->data = 3;
	third->next = nullptr;

	h->next = second;
	second->next = third;

	return h;
}

void print( Node * head_){
	
	Node *work(head_);
	
	while( work != nullptr){
		std::cout << work->data << " ";

		work = work->next;
	}

}

std::size_t length(const Node * n){

	const Node * work (n);
	std::size_t count(0);

	while( work != nullptr){

		count++;
		work = work->next;
	}

	return count;
}
bool empty( const Node * n){

	return (n == nullptr);
}

void push_front( Node * &head, int value){

	//Cria o novo nó
	Node * temp = new Node(value, nullptr);

	//Novo nó ponta para o primeiro elemento da lista
	temp->next = head;

	//Novo nó agora é primeiro elemento da lista
	head = temp;
}

bool push_back(Node * &head, int value){

	//Aloca novo nó
	Node * temp = new Node(value, nullptr);

	//Verifica se a lista é vazia
	if( head == nullptr){ 
		head = temp;
		return true;
	}

	//Percorre a lista até achar o ultimo elemento
	auto current = head->next;
	while( current != nullptr){

		//Quando achar o último, ele aponta para o novo nó
		if(current->next == nullptr){
			current->next = temp;
			return true;
		}
		current = current->next; //Avança na lista
	}

	return false;
}

void clear( Node * & head){

	//Se já estiver vazio, não faz nada
	if(head == nullptr) return;

	//Percorre a lista
	auto current = head->next;

	//Aloca arquivo temporario
	Node * temp = head;
	while( current != nullptr){
		
		current = current->next; //Avança

		delete [] temp; //Deleta anterior
		temp = current; //Avança
	}

	head = current;
}


Node * find(Node * head, int target){

	Node * res = nullptr;

	while( head != nullptr){
		if( head->data == target)
			return res;
		res = head;
		head = head->next;
	}

	return nullptr;

}

bool front( Node * head, int & value ){

	//Checa se a lista está vazia
	if( head != nullptr){
		if( head->data == value) return true;
	}

	return false;
}


bool back( Node * head, int & value ){

	//Percorre lista
	while( head != nullptr){
		//Checa se é o ultimo elemento da lista
		if(head->next == nullptr)
			if( head->data == value) return true; //Checa se é igual a value

		head = head->next; //Avança
	}

	return false;
}

bool pop_front(Node * & head, int & value ){

	if( head != nullptr){
		value = head->data;

		//Guarda o segundo
		Node * temp = head->next;

		//Head agora guarda o segundo
		head = temp;	

		return true;
	}

	return false;
}

bool pop_back(Node * & head, int & value ){

	//Checa se é vazio
	if(head == nullptr) return false;
	
	//Guarda o próximo
	Node * prox = head->next;

	//Guarda o atual
	Node * temp = head;

	//Percorre a lista
	while( prox != nullptr){
		//Se o próximo for o ultimo, apaga ele e retorna true
		if(prox->next == nullptr){			
			temp->next = nullptr;
			value = prox->data;
			delete prox;
			return true;
		}	

		temp = prox; //O atual avança
		prox = prox->next; //O proximo avança também
	}

	if( prox == nullptr){
		value = temp->data;
		head = nullptr;
		return true;
	}

	return false;
}

bool insert( Node * & head, Node * ant, int value ){

	Node * nNode = new Node(value, nullptr);

	Node * current = head;
	while( current != nullptr){

		if(current == ant){
			nNode->next = ant->next;
			ant->next = nNode;
			return true;
		}
		current = current->next;
	}
	push_front(head, value);

	return false;
}

bool remove( Node * & head, Node * ant, int & rValue ){

	Node * target(nullptr);

	if( head == nullptr) return true; //Lista vazia

	//Caso especial: ant = nullptr
	target = (ant == nullptr)? head : ant->next;

	//Marca o alvo
	if( ant != nullptr){
		ant->next = target->next;
	} else{
		head = target->next;
	}

	//Remove o marcado
	rValue = target->data;
	delete target;
	

	return true;

}

int main() {
	
	//Teste print
	Node * head (nullptr);
	Node * empt(nullptr);
	head = build123();
	//Teste print
	print(head);
	print(empt);
	std::cout << std::endl;

	//Teste length
	assert( length(head) == 3 );
	assert( length(empt) == 0);

	//Teste empty()
	assert( empty(empt));
	assert( empty(head) == false);

	//Teste push_front()
	push_front(head, 4);
	print(head);
	std::cout << std::endl;

	//Teste push_back()
	push_back(head, 10);
	print(head);
	std::cout << std::endl;

	//Teste clear()
	clear(head);	
	assert( empty(head));

	//Teste find()
	head = build123();
	auto f1 = find(head, 1);
	auto f2 = find(head, 5);
	auto f3 = find(head, 2);
	auto f4 = find(head, 3);
	assert( f1 == nullptr );
	assert( f2 == nullptr );
	assert( f3->data == 1);
	assert( f4->data == 2);


	//Teste front();
	auto value = 10;
	push_front(head, 10);
	assert( front(head, value));

	//Teste back()
	value = 0;
	push_back(head, value);
	assert( back(head, value) );

	//Teste popFront()
	int apagado;
	assert( pop_front(head, apagado) );
	assert( apagado == 10);

	//Teste pop_back()
	assert( pop_back(head, apagado) );
	assert( apagado == 0 );

	assert( pop_back(head, apagado) );
	assert( apagado == 3 );

	assert( pop_back(head, apagado) );
	assert( apagado == 2 );

	assert( pop_back(head, apagado) );
	assert( apagado == 1 );

	assert( empty(head) );


	//Teste insert()
	head = build123();
	auto f = find(head, 3);
	assert( insert(head, f, 5));
	//Vetor deve estar: 1 2 5 3
	f = find(head, 3);
	//5 deve ser o penultimo elemento
	assert( f->data == 5);


	//Teste remove()
	int removed;
	assert( remove(empt, empt, removed));
	assert( empty(empt) );

	assert( remove(head, head, removed));
	assert( removed == 2 );

	assert( remove(head, nullptr, removed) );
	assert( removed == 1);

	assert( remove( head, find(head, 3), removed));
	assert( removed == 3);

	assert( remove( head, find(head, 5), removed));
	assert( removed == 5);

	assert( empty(head) );
	
	std::cout << ">>> Passou em todos os testes!\n";

	return 0;
}