#include <iostream>

//lista encadeada
struct node {
	int data;
	node * next;

	node( int d_ = 0, node * n_ = nullptr ) : data( d_ ), next( n_ )
	{ /*empty*/ }
};

void push_front( node * &head_ref, int value_ )
{
	auto new_node = new node( value_, head_ref );
	head_ref = new_node;
}

void push_back( node * & head_ref, int value_ )
{
	auto tail( head_ref );

	while( tail != nullptr and tail->next != nullptr )
		tail = tail->next;

	//inserir no final
	if ( tail != nullptr )
		push_front( tail->next, value_ );
	else 
		push_front( head_ref, value_ );
}

std::ostream & operator<<( std::ostream & os_, const node * l_ )
{
	os_ << "{";
	//percorre a lista e imprime valores
	while ( l_ != nullptr )
	{
		os_ << l_->data << " ";
		l_ = l_->next;
	}
	os_ << "}";

	return os_;
}

int main ()
{
	node * head( nullptr );
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for( const auto & e : v )
		push_back( head, e );

	return EXIT_SUCCESS;
}