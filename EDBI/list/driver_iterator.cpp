#include <iostream>  // cout, endl
#include <iterator>  // bidirectional_iterator_tag
#include <cassert>   // assert()
#include <algorithm> // copy
#include <cstddef>   // std::ptrdiff_t

/*!
 * A template class representing a biderectional iterator defines
 * over a dynamic array.
 * 
 * \note
 * This iterator only works for traversing elements inside the same array.
 *
 * This class is incomplete and it is provided "as is".
 * 
 * \date May, 2nd 2017.
 * \author Selan R. dos Santos
 */
//Forward declaration
//aviso que no futuro existirá uma classe chamada list 

namespace ls{

template < typename T >
    class list;

template <typename T>
class MyBidirectionalIterator
{
    // =============================================================
    // Some aliases to help writing a clearer code.
    // =============================================================
    public:
        using self_type = MyBidirectionalIterator;  
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        /*!
         * \brief std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
         *
         * std::ptrdiff_t is used for pointer arithmetic and array indexing,
         * if negative values are possible. Programs that use other types, such
         * as int, **may fail** on, e.g. 64-bit systems when the index exceeds
         * INT_MAX or if it relies on 32-bit modular arithmetic.
         *
         * When working with the C++ container library, the proper type for the
         * difference between iterators is the member typedef difference_type,
         * which is often synonymous with std::ptrdiff_t.
         * Only pointers to elements of the same array (including the pointer
         * one past the end of the array) may be subtracted from each other.
         */
        using difference_type = std::ptrdiff_t;
        /*!
         * Defines the category of an iterator.
         * Iterator category tags carry information that can be used
         * to select the most efficient algorithms for the specific
         * requirement set that is implied by the category.
         */
        using iterator_category = std::bidirectional_iterator_tag;

        // =============================================================
        // The raw pointer we want to encapsulate.
        // =============================================================
    private:
        T * m_ptr; // node_t * m_ptr;

        // =============================================================
        // Public interface that mimics the behaviour of a regular pointer.
        // =============================================================
    public:
        // Constructor
        MyBidirectionalIterator( T * ptr_ = nullptr )
            : m_ptr ( ptr_ )
        { /* empty */ }

        // Special methods. Default versions.
        ~MyBidirectionalIterator() = default;
        MyBidirectionalIterator( const self_type & ) = default;
        self_type & operator=( const self_type & ) = default;

        /*! The  *it operator.
         *  Supports: *it = XXXX or XXXX = *it.
         *  \return A reference to the object this iterator points to.
         */
        //not_t::value_type & operator*()
        typename T::value_type & operator*()
        {
            assert( m_ptr != nullptr );
            return m_ptr->data;
        }

        /*! The ++it operator.
         *  \return The calling object.
         */
        self_type operator++()
        {
            m_ptr = m_ptr->next;
            return *this;
        }

        /*! The it++ operator.
         *  \return The calling object.
         */
        self_type operator++(int)
        {
            self_type temp = *this;
            m_ptr = m_ptr->next;
            return temp;
        }

        /*! The --it operator.
         *  \return The calling object.
         */
        self_type operator--()
        {
            m_ptr = m_ptr->prev;
            return *this;
        }

        /*! The it-- operator.
         *  \return The calling object.
         */
        self_type operator--(int)
        {
            self_type temp = *this;
            m_ptr = m_ptr->prev;
            return temp;
        }

        /// The it == it2 operator.
        bool operator==( const self_type & rhs_ ) const
        {
            return m_ptr == rhs_.m_ptr;
        }

        /// The it != it2 operator.
        bool operator!=( const self_type & rhs_ ) const
        {
            return m_ptr != rhs_.m_ptr;
        }

        // ==================================================
        /* Other methods that you might wanto to implement. */
        // ==================================================

        /// it += 3; // Go back  3 positions within the container. 
        self_type operator+=( difference_type step_ ) ;

        /// it -= 3; // Go back  3 positions within the container. 
        self_type operator-=(  difference_type step_ ) ;

        /// it->method()
        pointer operator->( void ) const
        {
            assert( m_ptr );
            return *m_ptr;
        }

        /// it1 - it2
        difference_type operator-( const self_type & rhs_ ) const ;

        friend class list<typename T::value_type >;

};

/// A simple version of a dynamic array that stores integers.
template <typename T>
class list
{
    struct node_t
    {
        typedef T value_type; // using value_type = T

        value_type data; // tipo de informação a ser armazenada
        node_t * next; //ponteiro para frente
        node_t * prev; // ponteiro para atras

        node_t ( const T & d_ = T() , node_t * n_ = nullptr, node_t * p_ = nullptr )
            : data ( d_ )
            , next ( n_ )
            , prev ( p_ )  
        { /*empty*/ }
    };

    // The iterator classes.
    public:
        //aponta para a estrutura não para um valor
        using iterator = MyBidirectionalIterator<node_t>;
        using const_iterator = MyBidirectionalIterator<const node_t>;

    // Internal data information.
    private:
        size_t m_len;
        node_t * m_head; // nó cabeça
        node_t * m_tail; //nó calda

    public:
    // Special members
        //default
        list()
            : m_len ( 0 )
            , m_head ( new node_t() )
            , m_tail ( new node_t() )
        {
            m_head->next = m_tail;
            m_tail->prev = m_head;
        }
        //copy constructor
        list ( const list & clone_)
            : m_len ( 0 )
            , m_head ( new node_t() )
            , m_tail ( new node_t() )
        {
            //copiar os dados de clone_ para this
            for ( auto it( clone_.begin() ) ; it != clone_.end() ; ++it )
                push_back( *it );

        }

        ~list()
        {
            //clear(); //apaga os nós da lista.
            delete m_head;
            delete m_tail;
        }

        iterator begin() 
        {
            return iterator ( m_head->next );
        }

        iterator end()
        {
            return iterator ( m_tail );
        }

        const_iterator cbegin() 
        {
            return const_iterator ( m_head->next );
        }

        const_iterator cend()
        {
            return const_iterator ( m_tail );
        }

        iterator insert( iterator it_, const T & value_ )
        {
            //1 alocar o nó new_node
            //2a new_node->next = it ( next do novo nó recebe it )
            // b new_node->prev = it->prev ( prev do novo nó recebe o prev do it )
            //3a (it->prev)->next = new_node ( o next do prev do it recebe novo nó )
            // b it->prev = new_node ( prev do iterador recebe novo nó )

            //(1) Alocar o novo nó
            node_t *new_node = new_node_t( value_ );

            //(2) Conectar o nó a nova lista
            new_node->next = it_.m_ptr;
            new_node->prev = it_->prev;

            //(3) Fazer a lista reconhecer o nó
            (it_->prev)->next = new_node; //o next anterior aponta para o novo nó
            it_->prev = new_node;

            //(4) Incrementar o contador de elementos
            m_len++;

            return iterator( new_node );
        }

         iterator erase( iterator it_ )
        {
            //TODO
            if ( it_ == end() ) return it_;

            auto before( it->prev );
            auto after( it->next );

            //(1) bypass o nó a ser removido
            before->next = after;
            after->prev = before;

            //(2) remover o nó marcado
            delete it_.m_ptr;

            return iterator( after );
        }

        bool empty()
        {
            
        }

        void push_front( const T & value_ )
        {
            insert ( begin(), value_ );
        }

        void push_back( const T & value_ )
        {
            insert( end(), value_ );
        }

        void pop_front( )
        {
            erase ( begin() );
        }

        void pop_back()
        {
            erase ( --end() );
        }



        friend std::ostream & operator<< ( std::ostream & os_, const ls::list<T> & l_ )
        {
            os_ << "[ ";
            for ( auto it( l_.cbegin() ); it != l_.cend(); ++it)
                os_ << *it << " ";
            os_ << "]";

            return os_;
        }

       
    // Public interface.
    
};

}

// The vector/iterator driver.
int main( void )
{
    ls::list< int > v;
    //for ( )

    return 0;
}
