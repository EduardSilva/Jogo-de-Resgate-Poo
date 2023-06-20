#ifndef GAME
#define GAME

#include "Fase.hpp"
#include <vector>
	using std::vector;
class Game {

	public:
	Game(): atual(0)
	{
		//faz um belo nada 
	}
	virtual int run()=0;
	void adciona_fase(Fase &a)
	{
		fases.push_back(&a);
	}
	protected:
	vector<Fase*> fases;
	int atual;
};



#endif
