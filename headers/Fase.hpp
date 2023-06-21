#ifndef FASE
#define FASE
#include "Screen.hpp"
#include <list>
	using std::list;
#include <stdlib.h>

bool ordenar_objetos(const Obj_de_Jogo &,const Obj_de_Jogo &);

class Fase {

	public:
	Fase(Screen &s);
	virtual int run()=0;
	void show() 
	{ 
	system("clear");
	for (auto a : objetos) *screen << a;
		screen->Draw();
	}
	Fase & operator<<(const Obj_de_Jogo &);
	
	protected:
	Screen *screen;
	list<Obj_de_Jogo> objetos;
};

class Fase1 :public Fase{
	public:
	Fase1(Screen & s): Fase(s)
	{
		//nada
	}
	
	int run();
};

class Fase2 :public Fase{
	public:
	Fase2(Screen & s): Fase(s)
	{
		//nada dnv
	}
	int run();
	void show();
	Fase2 & operator<<(const Obj_de_Jogo &);
	Fase2 & operator<<(const Pessoa &);
	void setHeli(Helicoptero & h){
		heli = &h;
	}
	private :
	Helicoptero *heli;
	list<Pessoa> pessoas;
};

class Fase3: public Fase{
	public:
	Fase3(Screen & s): Fase(s)
	{
		
	}
	int run() {
		show();
		return -1;
	}
};

class Fase4: public Fase{
	public:
	Fase4(Screen & s): Fase(s)
	{
		
	}
	int run() {
		show();
		return -1;
	}
};


#endif
