#include "Sprite.hpp"
#include "Screen.hpp"
#include <fstream>
	using std::ifstream;
#include <iostream>
	using std::cout;
#include <string>
	using std::string;

Screen::Screen(int x, int y):
 SpriteBase(), screen (x, vector<char>(y, ' '))
{
	tamv = x-1;//regular limite da tela pra que
	tamh = y-1;//as bordas não sejam preenchidas

	for (int i = 0; i < x; i++){
		screen[i][0] = '|';
		screen[i][y-1] = '|'; 
	}
	for (int i = 0; i < y; i++){
		screen[0][i] = '-';
		screen[x-1][i] = '-';
	}	
	
}	
	



Screen & Screen::operator<<(const Obj_de_Jogo &obj){
	if (! obj.esta_ativo() ) return *this;
		
	if ((obj.x + obj.box[1] > tamv) or (tamh < obj.y + obj.box[0])) return *this;

	vector< vector<char> > sprite =obj.orientação == 'D' ? obj.sprite->getSprite() :
		obj.sprite->getRSprite();
	int x = obj.x; //variavel que representa as linhas 
	int y = obj.y; //variavel que representa as colunas
	int limv = sprite.size();
	for(int i = 0; i < limv; i++, x++){
		int limh = sprite[i].size();
		
		for(int j = 0; j < limh; j++, y++){

			if (sprite[i][j] == ' ') continue;

			screen[x][y] = sprite[i][j];
		}

		y = obj.y; //refresh das colunas
	}

	return *this;
}


void Screen::Draw(){
	for (int x=0; x <= tamv; x++ ){
		for (int y = 0; y <= tamh; y++){
			cout << screen[x][y];
		}
		cout <<std::endl;
	}
	
}

vector<vector <char> > Screen::getRSprite(){
	vector<vector<char>> retorno;
	
	for (int i = 0; i < tamv; i++){
	
		int limite = screen[i].size();
		vector<char> linha;
		
		for(int j = limite-1; 0 <= j; j--){
			
			linha.push_back(screen[i][j]);
		}
	
		retorno.push_back(linha);
	}

	return retorno;
}

