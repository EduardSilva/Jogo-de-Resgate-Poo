#include "../headers/Game.hpp"


int GameHeli::run(){

	vector<Fase*>::iterator it = fases.begin();
	std::advance(it,atual);

	int retorno;
	retorno = (*it)->run();	

	if(retorno > 0 ) {
		troca_fase(retorno);
		run();
		}
	else if (retorno == -1) return 0;
		
	if (retorno ==-2){
	troca_fase(3);
	run();
	return 0;}
	
	return 0;
}

