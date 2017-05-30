#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>

class Maze{



};

struct Position{
	size_t row;
	size_t col;
};

bool solve_maze( Maze& mz_, const Position& pos_ )
{

}

int main ( int argc, char *argv[] )
{
	Maze mz;

	mz.load_board( argv[1] );
}
{

	int line, col;
	std::string date;

	//abrir arquivo
	std::ifstream maze;
	maze.open( "maze.txt", std::ifstream::in);
	std::cout << "abriu\n";

	//pegar primeira linha com linha e coluna
	maze.getline(std::cin, date);
	std::string aux;
	auto i(0u);
	auto tam = date.size();
	std::cout << "TAM: " << tam << std::endl;

	while ( i != tam )
	{
		if( date[i] == ' ' )
		{
			line = std::stoi( aux );
			aux.clear();
		}

		aux.push_back( date[i] );
		i++;
	}

	col = std::stoi( aux );
	std::cout << "LINES: " << line << ", COLs: " << col << std::endl;

	maze.close();

	return EXIT_SUCCESS;
}