#include "graal.h"


namespace graal {
    using byte = unsigned char;

    void transform( void *first, void *last, std::size_t size, void (*func) ( void * ) )
    {
        byte *f = ( byte * ) first; // Converter para byte, para aplicarmos operacoes.
        byte *l = ( byte * ) last;

        // Percorrer todo o range.
        while ( f != l )
        {
            func( f );  // Aplicando a transformacao.
            f += size;  // equivalente a first++;
        }
    }

    const void * find( void *first, void *last, std::size_t size,
                       const void * target, bool (*eq)( const void*, const void* ) )
    {
        byte *f = ( byte * ) first; // Converter para byte, para aplicarmos operacoes.
        byte *l = ( byte * ) last;

        // Avancar ao longo do range.
        while ( f != l )
        {
            if ( eq( f, target ) ) // *f == *target ?
                return f;
            f += size;
        }

        return last;  // return l; return f;
    }
}
