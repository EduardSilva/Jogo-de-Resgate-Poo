#include <iostream>
	using std::cout; 
#include "../headers/Screen.hpp"
#include "../headers/Obj_de_Jogo.hpp"
#include "../headers/Sprite.hpp"
	using namespace std;
#include <string>	
int main(){
	Screen tela(25, 40);	
	SpriteAnimado helis("sprite.txt");
	SpriteAnimado pessoaS("Pessoa.txt");
	Obj_de_Jogo heli(1,2, 0, true, helis);
	Obj_de_Jogo pessoa (12, 1, 0, true, pessoaS);

	cout << heli.colidindo_com(pessoa) <<endl;
	tela << pessoa << heli;
	tela.Draw();
	pessoa.mover_se(1,5, false);
	cout << heli.colidindo_com(pessoa) <<endl;
	tela << pessoa << heli;
	tela.Draw();
	return 0;
}
