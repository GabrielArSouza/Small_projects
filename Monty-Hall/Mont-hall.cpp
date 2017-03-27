#include <iostream>
#include <cstdlib>

int main ()
{
	auto win(0.f);
	auto lose(0.f);

	int r, player, open, Ndoor, plays;
	srand (time(NULL));

	std::cout << "Quantas jogadas?" << std::endl;
	std::cin >> plays;
		
	//trocando a porta
	//testar 10 mil vezes
	for(auto i(0); i < plays; ++i)
	{
		//gerando a porta premiada
		r = rand() % 3 + 1; //1, 2 ou 3
		
		//jogador escolhendo a porta
		player = rand() % 3 + 1;

		//abrir uma porta vazia
		do {
			open = rand() % 3 + 1;
		}while(open == r || open == player);

		//jogador troca de porta
		do {
			Ndoor = rand() % 3 + 1; 
		}while(Ndoor == player || Ndoor == open);

		if (Ndoor == r) win++;
		else lose++;
	}
	std::cout << "JOGADAS: "<< plays << std::endl;	
	
	std::cout << "JOGADOR TROCANDO A PORTA" << std::endl;
	std::cout << "VENCIDAS: " << win << std::endl;
	std::cout << "PERDIDAS: " << lose << std::endl;
	std::cout << "\tVENCER: " << win/plays*100 << "%" << std::endl;
	std::cout << "\tPERDER: " << lose/plays*100 << "%" << std::endl;
	win = 0;
	lose = 0;

	//sem trocar a porta
	//testar 10 mil vezes
	for(auto i(0); i < plays; ++i)
	{
		//gerando a porta premiada
		r = rand() % 3 + 1; //1, 2 ou 3
		
		//jogador escolhendo a porta
		player = rand() % 3 + 1;

		//abrir uma porta vazia
		do {
			open = rand() % 3 + 1;
		}while(open == r || open == player);

		if (player == r) win++;
		else lose++;
	}
	
	std::cout << "JOGADOR NÃO TROCA A PORTA" << std::endl;

	std::cout << "VENCIDAS: " << win << std::endl;
	std::cout << "PERDIDAS: " << lose << std::endl;
	std::cout << "\tVENCER: " << win/plays*100 << "%" << std::endl;
	std::cout << "\tPERDER: " << lose/plays*100 << "%" << std::endl;

	return EXIT_SUCCESS;
}