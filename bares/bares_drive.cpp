/*!
 * Infix to postfix conversion in C++
 * Input Postfix expression must be in a desired format.
 * Operands and operator, **both must be single character**.
 * Only '+', '-', '*', '%', '/', and '^' (for exponentiation) operators are expected;
 * Any other character is just ignored.
 */
#include <iostream>  // cout, endl
#include <stack>     // stack
#include <string>    // string
#include <cassert>   // assert
#include <cmath>     // pow
#include <algorithm>

int char2int( char ch )
{
	return ch - '0';
}
bool is_operator ( char c );

bool is_operand ( char c );

bool is_opening_scope( char c );
bool is_closing_scope( char c );

// operador first > segundo
bool has_higher_precedence( char op1, char op2 );

/// Converts a expression in infix notation to a corresponding profix representation.
std::string infix_to_postfix( std::string );

int execute_operator(char a, char b, char opr)
{
	auto n1 = char2int(a);
	auto n2 = char2int(b);

	switch ( opr )
	{
		case '^' : return (int) pow(n1,n2);
		case '*' : return n1*n2; 
		case '/' : 
				   // if ( n2 == 0 ) th
					return n1/n2;
		case '%' : //exception
					return n1%n2;
		case '-' : return n1-n2;
		case '+' : return n1+n2;
		default:
				assert(false);
	}
}

int evaluate_postfix( std::string postfix_ )
{
	std::stack<int> s;

	for ( auto ch : postfix_ )
	{
		if ( is_operand(ch))
		{
			s.push(char2int(ch));
		}
		else if ( is_operator(ch) )
		{
			auto op2 = s.top(); s.pop();
			auto op1 = s.top(); s.pop();

			auto result = execute_operator( op1, op2, ch);
			s.push(result);
		}
		else
		{
			assert(false);
		}
	}

	return s.top();
}



int main()
{
    std::string expression = "4/(5^2)+(6^2^3)";
    std::string expression2 = "1+ 3 * ( 4 + 8 * 3 ^7)";
    //std::string expression = "A+(B*C-(D/E^F)+G)*H";
    //
    auto postfix = infix_to_postfix(expression2);
    std::cout << ">>> Input (infix)    = " << expression2 << "\n";
    std::cout << ">>> Output (postfix) = " << postfix << "\n";

    auto result = evaluate_postfix( postfix );
    std::cout << ">>> Result is: " << result << std::endl;
    std::cout << "\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;
}

std::string infix_to_postfix( std::string infix_ )
{
	//Stores the postfix expression 
	std::string postfix; //output
	// stack to help us convert the expresion.
	std::stack< char > s;

	// Traverse the expression
	for ( auto ch : infix_ )
	{	
		if ( is_operand( ch ) ) // 1 23 100, etc
		{
			postfix += ch;
		}
		else if ( is_operator( ch ) ) // + - ^ %, etc
		{
			// pop out all the element with higher priority.
			while ( not s.empty() and has_higher_precedence( s.top(), ch) )
			{
				postfix += s.top();
				s.pop();
			}
			// sempre vai entrar
			s.push( ch );
		}
		else if ( is_opening_scope( ch ) ) // "("
		{
			s.push(ch);
		}
		else if ( is_closing_scope( ch ) ) // ")"
		{
			// pop out all elements that are not '('
			while ( not s.empty() and not is_opening_scope( s.top() ) )
			{
				postfix += s.top();
				s.pop();
				
			}
			s.pop();
		}
		else // anything else
		{
			//ignore this char.
		}
	}

	// remove a galera que ficou de boas
	while ( not s.empty() )
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;

	//
}

bool is_operator ( char c )
{
	std::string operators = "+-%^/*";

	return operators.find( c ) != std::string::npos;
}

bool is_operand ( char c )
{
	return ( c >= '0' and c <= '9');
}

bool is_opening_scope( char c )
{
	return c == '(';
}
bool is_closing_scope( char c )
{
	return c == ')';
}

bool is_right_association( char op )
{
	return op == '^';
}

int get_precedence ( char c )
{
	int weight(0);
	switch( c )
	{

		//====================
		case '^': weight = 3;
				  break;
		//====================
		case '*': 
		case '%':
		case '/': weight = 2;
				  break;
		//====================
		case '+':
		case '-': weight = 1;
				  break;
		//====================
		case '(': 
				 weight = 0;
				 break;
		default:
			assert(false);
	}
	return weight;
}

// operador first > segundo
bool has_higher_precedence( char op1, char op2 )
{
	//op1 operador que está no topo
	auto p1 = get_precedence(op1);
	auto p2 = get_precedence(op2);

	//has the same precedence?
	if ( p1 == p2 )
	{
		if ( is_right_association(op1 ) )
			return false;
	}
	// topo >= entrando
	return p1 >= p2;
}