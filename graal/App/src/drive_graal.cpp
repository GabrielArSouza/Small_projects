#include <iostream>
#include <iterator>
#include <cctype>   // toupper, tolower
#include <string>

#include "graal.h"

/// Displays on the screen (std::cout) the content of a range of integers.
void print( int * first_, int * last_ )
{
    std::cout << "[ ";
    while( first_ < last_ )
    {
        std::cout << *first_ << " ";
        first_++;
    }
    std::cout << "]";
}

void inverter_sinal( void * e )
{
    int * ptr = ( int * ) e; // Converter para inteiro.

    *ptr *= -1;
}
void multiplicar_10( void * e )
{
    int * ptr = ( int * ) e; // Converter para inteiro.

    *ptr *= 10;
}


void inverter_caixa( void * e )
{
    char * c = ( char * ) e;

    *c = ( std::isupper( *c ) ) ? std::tolower( *c ) : std::toupper( *c ) ;
}

void imprimir_caractere( void * e )
{
    char * c = (char *) e;
    std::cout << "\'" << *c << "\'";
}

void imprimir_int( void * e )
{
    int * c = (int *) e;
    std::cout << *c << " ";
}

bool compare( const void *a, const void *b )
{
    auto aa = ( const int *) a;
    auto bb = ( const int *) b;

    return *aa == *bb;
}

bool compare_char( const void *a, const void *b )
{
    auto aa = ( const char *) a;
    auto bb = ( const char *) b;

    return *aa == *bb;
}

bool eh_par( const void * e )
{
    auto x = ( const int * ) e;

    return ( (*x)%2 == 0 );
}

int main( void )
{
#ifdef NOT_IMPLEMENTED
    // Testando all_of, any_of, none_of
    {
        int A[] = { 2, -3, 4, 8, -5, 8, 7 };

        std::cout << ">> Todos os elementos sao pares? "
            << std::boolalpha( graall::all_of( std::begin(A), std::end(A), eh_par ) )
            << std::endl;

        std::cout << ">> Algum dos elementos sao pares? "
            << std::boolalpha( graall::any_of( std::begin(A), std::end(A), eh_par ) )
            << std::endl;

        std::cout << ">> Nenhum dos elementos sao pares? "
            << std::boolalpha( graall::none_of( std::begin(A), std::end(A), eh_par ) )
            << std::endl;
    }
#endif

    // Testando find()
    {
        int A[] = { 2, -3, 4, 8, -5, 8, 7 };
        auto target1( 8 );
        auto target2( 18 );
        
        std::cout << ">>> Array A: [";
        graal::transform( std::begin(A), std::end(A), sizeof(int), imprimir_int );
        std::cout << "]\n";

        auto result1 = ( int * ) graal::find( std::begin(A), std::end(A), sizeof(int),
                &target1, compare );
        auto result2 = ( int * ) graal::find( std::begin(A), std::end(A), sizeof(int),
                &target2, compare );


        // Achou o target1?
        std::cout << ">>> Procurando pelo elemento " << target1 << " no vetor.\n";
        if ( result1 == std::end(A) )
            std::cout << ">>> Elemento nao encontrado!\n";
        else
            std::cout << ">>> Elemento encontrado na posicao "
                << std::distance( std::begin(A), result1 ) << ".\n";

        // Achou o target2?
        std::cout << ">>> Procurando pelo elemento " << target2 << " no vetor.\n";
        if ( result2 == std::end(A) )
            std::cout << ">>> Elemento nao encontrado!\n";
        else
            std::cout << ">>> Elemento encontrado na posicao "
                << std::distance( std::begin(A), result2 ) << ".\n";


        std::string s = "Exemplo de Uma String";
        auto target3('U'); // Procurar pela letra U.

        auto result3 = ( char * ) graal::find( &s[0], &s[s.size()], sizeof(char),
                &target3, compare_char );

        std::cout << ">>> Procurando pela letra \'" << target3 << "\' na string.\n";
        if ( result3 == &s[s.size()] )
            std::cout << ">>> Elemento nao encontrado!\n";
        else
        {
            std::cout << ">>> Elemento encontrado na posicao "
                << std::distance( &s[0], result3 ) << ".\n";
        }
    }


    // Uso do tansform()
    {
        int A[] = { 2, -3, 4, 8, -5, 8, 7 };

        std::cout << "\n>>> Before transform, A: ";
        //print( std::begin(A), std::end(A) );
        graal::transform( std::begin(A), std::end(A), sizeof(int), imprimir_int );
        std::cout << std::endl;

        std::cout << ">>> Multiplicando cada elemento por 10.\n";
        graal::transform( std::begin(A), std::end(A), sizeof(int), multiplicar_10 );

        std::cout << ">>> After transform, A: ";
        print( std::begin(A), std::end(A) );
        std::cout << std::endl;


        std::string s = "Exemplo de Uma String";
        std::cout << ">>> String: " << s << std::endl;

        graal::transform( &s[0], &s[s.size()], sizeof( char ), inverter_caixa );

        std::cout << ">>> String transformada: " << s << std::endl;

        std::cout << ">>> Usando transform para imprimir na tela:\n";
        graal::transform( &s[0], &s[s.size()], sizeof( char ), imprimir_caractere );
        std::cout << std::endl;
    }

    return 0;
}
