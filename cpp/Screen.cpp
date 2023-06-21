#include "../headers/Sprite.hpp"
#include "../headers/Screen.hpp"
#include <fstream>
	using std::ifstream;
#include <iostream>
	using std::cout;
#include <string>
	using std::string;
	
Screen::Screen(int x, int y, string file):
 SpriteBase()
{
	tamv = x-1;//regular limite da tela pra que
	tamh = y-1;//as bordas não sejam preenchidas

	ifstream arqI;
	arqI.open(file, ifstream::in);	//abrir o arquivo
	if (! arqI.is_open()){
			cout << "O sprite presente no arquivo :" << file 
			<<" não foi aberto" << std::endl;
			exit(1);
		}
		
	string linha_texto;
	int j = 1; 
	while(getline(arqI, linha_texto)){
		int linha_tam = linha_texto.size();
		vector<char> linha;
		for (int i = 1; i < linha_tam; i++){
		
			linha.push_back(linha_texto[i]);
		}

		screen.push_back(linha);
		j++;
	}

	arqI.close();
	
	clean = screen;
}	
	



Screen & Screen::operator<<(const Obj_de_Jogo &obj){
	if (! obj.esta_ativo() ) return *this;

	const int* box = obj.get_box();
	if ((obj.x + box[0] > tamv) or (tamh < obj.y + box[1])) return *this;

	vector< vector<char> > sprite = obj.sprite->getSprite();
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
	for (int x = 0; x <= tamv; x++ ){
		cout << " ";
		for (int y = 0; y <= tamh; y++){
			cout << screen[x][y];
		}
		cout <<std::endl;
	}
	
	screen = clean;
}



