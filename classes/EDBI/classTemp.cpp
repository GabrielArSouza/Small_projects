#include <iostream>
#include <string>

template <typename T>
class MemoryCell {
	
	private:
		int *m_cell;

	public:
		//construtor default
		MemoryCell()
		{
			std::cout << ">>> construtor default.\n";
			m_cell = new T;
		}

		//construtor copia
		MemoryCell (const MemoryCell & copy_ )
		{
			std::cout << ">>> construtor cópia.\n";
			m_cell = new T;
			//copiando o conteúdo das células
			*m_cell = *copy_.m_cell;
		}

		//operador de atribuição cópia
		MemoryCell& operator=( const MemoryCell & rhs_ )
		{
			std::cout << ">>> opeardor atribuição cópia.\n";
			return *this;
		}

		//destruidor
		~MemoryCell()
		{
			std::cout << ">>> Destruidor.\n";
			delete m_cell;
		}

		void write ( T value_ )
		{
			*m_cell = value_;
		}

		T read (void) const
		{
			return *m_cell;
		}

};

template <typename T>
void print ( MemoryCell<T> x )
{
	std::cout << ">>> m_cell = " << x.read() << "\n";
} 

int main ()
{
	MemoryCell <int> a;
	MemoryCell <std::string> s;

	s.write("exemplo");

	a.write( 10 );

	MemoryCell <int> b(a);

	print ( b );

	std::cout << ">>> O valor de a é: " << a.read() << "\n";

	std::cout << ">>> O valor de s é: " << s.read() << "\n";

}