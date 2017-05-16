#include <iostream>

template <typename T>
class MemoryCell{

	private:

		T *m_cell;

	public:	
		//Default
		MemoryCell(){
			m_cell = new T;

		}

		//Construtor copia
		MemoryCell (const MemoryCell &copy){
			m_cell = new T;
			*m_cell = *copy.m_cell;
		}

		//atribuiçao por copia
		MemoryCell& operator=(const MemoryCell &rhs_){
			return *this;
		}

		//Destrutor
		~MemoryCell(){
			delete m_cell;

		}

		void write(T value){
			*m_cell = value;
		}

		T read(void) const{
			return *m_cell;
		}
};

template <typename T>
void print( MemoryCell <T> c){
	std::cout << "m_cell=" << c.read() << '\n';
}

int main(){

	MemoryCell<int> a;

	a.write(10);

	MemoryCell<int> b(a);

	std::cout << "Valor: " << a.read() << std::endl;
	print(b);

	return EXIT_SUCCESS;
}