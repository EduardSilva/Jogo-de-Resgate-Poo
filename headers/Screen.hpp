#ifndef SCREEN
#define SCREEN
#include "Obj_de_Jogo.hpp"
#include "Sprite.hpp"
#include <string>
	using std::string;
#include <vector>
	using std::vector;

	
class Screen : public SpriteBase {

	public:
	//Construtor
	Screen(int, int);
	Screen &  operator<<(const Obj_de_Jogo &);
	void Draw();
	vector<vector <char> > inline getSprite(){return screen;};
	private:
	vector<vector <char> >screen;
	vector<vector <char> >clean;
	
};


#endif
