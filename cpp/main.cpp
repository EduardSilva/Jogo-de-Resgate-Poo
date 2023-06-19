#include <iostream>
	using std::cout; 
#include "Screen.hpp"
#include "../Obj_de_Jogo/Obj_de_Jogo.hpp"
#include "Sprite.hpp"
int main(){
	Screen a(25, 40);	
	Sprite b ("sprite.txt");
	Obj_de_Jogo c(1,2, 0, 'D', true, b);
	c.draw();
	a << c;
	a.Draw();
	
	return 0;
}
