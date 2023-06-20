#ifndef FASE
#define FASE
#include "Screen.hpp"
#include <list>
	using std::list;

bool ordenar_objetos(const Obj_de_Jogo &,const Obj_de_Jogo &);

class Fase {

	public:
	Fase(Screen &s);
	virtual void run()=0;
	void show() { screen->Draw();}
	void operator<<(const Obj_de_Jogo &);
	
	protected:
	Screen *screen;
	list<Obj_de_Jogo> objetos;
};


#endif
