#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib> // size_t
#include <stdexcept> // out_of_range
#include <iostream> // cout, endl
#include <cassert>  // assert
#include <algorithm> // copy
#include <iterator>  // ostream_iterator

// Linear Sequence: LS
namespace ls {

    template <typename T>
    class vector
    {
        private:
            //!< Defatul size for the vector.
            static constexpr size_t DEFAULT_SIZE{ 0 };

            size_t m_len;  //!< Logical length.
            size_t m_size; //!< Actual size of the array.
            T *m_data;   //!< Dynamic storage area.

        public:
            vector( size_t sz_=DEFAULT_SIZE )
                : m_len(0)
                , m_size( sz_ )
                , m_data(new T[ sz_ + 1 ]) // +1 eh necessario para a posicao extra do end().
            {
                /*
                m_data = new int[ sz_ ];
                m_len = 0;
                m_size = sz_;
                */
            }

            ~vector( )
            {
                delete [] m_data;
            }

            void clear( void )
            {
                m_len = 0;
            }

            size_t capacity( void ) const
            {
                return m_size;
            }

            bool empty( void ) const
            {
                return m_len == 0;
            }
            bool full( void ) const
            {
                return m_len == m_size;
            }

            T front( void ) const
            {
                if ( empty() )
                    throw std::out_of_range("[front()]: Cannot recover an element from an empty vector!");

                return m_data[0];
            }

            T back( void ) const
            {
                if ( empty() )
                    throw std::out_of_range("[back()]: Cannot recover an element from an empty vector!");

                return m_data[m_len-1];
            }

            void push_back( const T & value_ )
            {
                if ( full() )
                    resize( 2* m_size );
                    //throw std::length_error( "[push_back()]: vector is full!!!" );

                m_data[m_len++] = value_;
            }

            void print( void ) const
            {
                std::cout << ">>> [ ";
                std::copy( &m_data[0], &m_data[m_len],
                           std::ostream_iterator< T >(std::cout, " ") );
                std::cout << "], len: " << m_len << ", capacity: " << m_size << ".\n";
            }

            T pop_back( void )
            {
                if ( empty() )
                    throw std::out_of_range("[pop_back()]: Cannot recover an element from an empty vector!");

                return m_data[--m_len];
            }

            /*
            push_front();
            pop_front();
            */
    };
}


int main()
{
    ls::vector<int> v( 100 );
    ls::vector<int> v2;

    // Testando excecao no front()
    {
        auto deu_certo{ false };
        try {
            std::cout << v2.front() << std::endl;
        }
        catch( const std::out_of_range & e )
        {
            deu_certo = true;
        }
        assert( deu_certo );
    }


    // Testando excecao no back()
    {
        auto deu_certo{ false };
        try {
            std::cout << v2.back() << std::endl;
        }
        catch( const std::out_of_range & e )
        {
            deu_certo = true;
        }
        assert( deu_certo );
    }

    // Testando metodo emtpy()
    {
        assert( v.empty() == true );
        assert( v2.empty() == true );
    }

    {
        for( auto i(0) ; i < 10 ; ++i )
            v.push_back( i+1 );

        v.print();

        while( not v.empty() )
            std::cout << v.pop_back() << " ";
        std::cout << std::endl;

        v.print();
    }

    ls::vector< std::string > ss;
    ss.push_back( "one" );
    ss.push_back( "two");
    ss.print();


    return 0;
}

#endif
