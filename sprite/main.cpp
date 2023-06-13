#include <iostream>
	using std::cout; 
#include "Sprite.hpp"

int main(){

	cout << "sprite animado"<< std::endl;	
	SpriteAnimado b("sprite.txt", 0x0);
	b.Draw();
	b.trocar_orientação();
	b.Draw();
	
	return 0;
}
