#include "Sprite.hpp"
#include <iostream>
	using std::cout; 
#include <fstream>
	using std::ifstream;
#include <string>
	using std::string;

	
SpriteBase::SpriteBase (string arquivo): orientação('D'){
	
	ifstream arqI;
	arqI.open(arquivo, ifstream::in);	//abrir o arquivo
	if (! arqI.is_open()){
			cout << "O sprite presente no arquivo :" << arquivo 
			<<" não foi aberto" << std::endl;
			exit(1);
		}
		
	string linha_texto;
	int h = 0; //linha

	this->tamv = 0;//define o tamanho maximo vertical como 0

	
	while(getline(arqI, linha_texto)){
		int linha_tam = linha_texto.length();
		vector<char> linha;
		for (int l = 0; l < linha_tam; l++){ //l = coluna = 0; coluna < tam da string
			linha.push_back(linha_texto[l]);
			if (l > this->tamh) tamh = l;
		}

		this->sprite.push_back(linha);
		
		h++;
	}

	this->tamv = h;


	arqI.close();
};


void Sprite::Draw(){
	
	if (this->orientação == 'D'){
		for (int v = 0; v < this->tamv; v++){
			for(int h = 0; h < this->tamh; h++){
				cout << this->sprite[v][h];
			}
		cout << std::endl;
		}
	}
	
};

