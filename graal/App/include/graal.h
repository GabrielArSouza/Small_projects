#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>
#include <cstring>

namespace graal {
	using Predicate = bool (*)(const void *);
    /*!
     *
     * \param first Inicio do range.
     */
    void transform( void *first, void *last, std::size_t size, void (*func) ( void * ) );

    const void * find( void *first, void *last, std::size_t,
                       const void * target, bool (*eq)( const void*, const void* ) );

    void * partition ( void * first , void * last , size_t size , Predicate p );
 	//bool all_of ( const void * first , const void * last , Predicate p );
	// bool any_of ( const void * first , const void * last , Predicate p );
	// bool none_of ( const void * first , const void * last , Predicate p );
}

#endif
