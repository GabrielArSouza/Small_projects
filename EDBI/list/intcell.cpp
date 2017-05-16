#include <iostream>

template <typename T>
class MemoryCell
{
    public:
        // Construtor default
        MemoryCell()
        {
            std::cout << ">>> Construtor default.\n";
            m_cell = new T;
        }

        // Construtor copia
        MemoryCell( const MemoryCell & copy_ )
        {
            std::cout << ">>> Construtor copia.\n";
            m_cell = new T;
            // Copiando o conteudo da celula.
            *m_cell = *copy_.m_cell;
        }

        // operador de atribuicao por copia
        MemoryCell& operator=( const MemoryCell & rhs_ )
        {
            std::cout << ">>> operador atribuicao copia.\n";

            return *this;
        }

        // Destrutor
        ~MemoryCell()
        {
            std::cout << ">>> Destrutor.\n";
            delete m_cell;
        }

        void write( T value_ )
        {
            *m_cell = value_;
        }

        T read( void ) const
        {
            return *m_cell;
        }

    private:
        T *m_cell;
};


template <typename T>
void print( MemoryCell<T> x )
{
    std::cout << ">>> m_cell = " << x.read() << '\n';
}

int main()
{
    std::vector< int > v;


    MemoryCell<int> a;
    MemoryCell< std::string > s;

    s.write ( "exemplo" );

    a.write( 10 );

    MemoryCell<int> b(a);

    print( b );

    std::cout << ">> O valor de a eh: " << a.read() << std::endl;

    std::cout << ">> O valor de s eh: " << s.read() << std::endl;
    print( s );

    return 0;
}
