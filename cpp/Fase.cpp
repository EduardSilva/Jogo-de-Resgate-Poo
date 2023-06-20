#include "../headers/Fase.hpp"

bool ordenar_objetos(const Obj_de_Jogo &a, const Obj_de_Jogo &b){

	return a.get_prioridade() < b.get_prioridade();
}


Fase::Fase(Screen &s){
	screen = &s;
}

void Fase::operator<<(const Obj_de_Jogo & o){
	objetos.push_back(o);
	objetos.sort(ordenar_objetos);
	
}
