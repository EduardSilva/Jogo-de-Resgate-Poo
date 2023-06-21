#include "../headers/Game.hpp"
#include "../headers/Fase.hpp"
#include "../headers/Obj_de_Jogo.hpp"
#include "../headers/Screen.hpp"
#include "../headers/Sprite.hpp"
#include "../headers/setups.hpp"
#include <iostream>
	using std::cout;
	
int main (){

	GameHeli Game;
	Screen tela(40, 160, "../sprites/fase_1.txt");

	Fase1 f1(tela);
	setupf1(f1);

	Fase2 f2(tela);
	setupf2(f2);

	Fase3 f3(tela);
	setupf3(f3);

	Fase4 f4(tela);
	setupf4(f4);
	
	Game.adciona_fase(f1);
	Game.adciona_fase(f2);
	Game.adciona_fase(f3);
	Game.adciona_fase(f4);
	Game.run();
	return 0;
}
