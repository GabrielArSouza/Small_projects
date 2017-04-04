#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>

namespace graal {

    /*!
     *
     * \param first Inicio do range.
     */
    void transform( void *first, void *last, std::size_t size, void (*func) ( void * ) );

    const void * find( void *first, void *last, std::size_t,
                       const void * target, bool (*eq)( const void*, const void* ) );

}

#endif
