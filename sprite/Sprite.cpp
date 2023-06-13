#include "Sprite.hpp"
#include <iostream>
	using std::cout; 
#include <fstream>
	using std::ifstream;
#include <string>
	using std::string;
#include <algorithm> 
	using std::for_each;


//relacionados a Sprite

Sprite::Sprite (string arquivo): SpriteBase() {
	
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
			
		}
		if (linha_tam > this->tamh) 
			this->tamh = linha_tam;
			
		this->sprite.push_back(linha);
		
		h++;
	}

	this->tamv = h;


	arqI.close();
};


Sprite::Sprite(vector<vector <char> > sprite, int v, int h): SpriteBase(){

	this->sprite = sprite;
	this->tamv = v;
	this->tamh = h;
		 
};




void Sprite::Draw(){
	//refatorado para melhor atualização.	
};

//relacionados a Sprite animado

SpriteAnimado::SpriteAnimado( string arquivo, char sep = 0x0): SpriteBase(), estagio(0) {

	ifstream arqI;
	arqI.open(arquivo, ifstream::in);	//abrir o arquivo
	if (! arqI.is_open()){	
			cout << "O sprite presente no arquivo :" << arquivo 
			<<" não foi aberto" << std::endl;
			exit(1);
		}
		
	string linha_texto;
	vector <vector <char>> atual;
	int h =0, v = 0;
	
	while(getline(arqI, linha_texto)){

		if(linha_texto[0] != sep){
			v++;
			int linha_tam = linha_texto.length();
			vector<char> linha;
			for (int l = 0; l < linha_tam; l++){ //l = coluna = 0; coluna < tam da string
				linha.push_back(linha_texto[l]);
				
			}
			if (linha_tam > h) 
				h = linha_tam;
				
			atual.push_back(linha);
			}
			
		else{
			Sprite a(atual, v, h);
			this->sprite.push_back(a);
			h = v = 0;
			atual.clear();
		}
	}


	arqI.close();
};

void SpriteAnimado::Draw(){

	sprite[estagio].Draw();
	atualizar_estagio();
		
	
}


void SpriteAnimado::atualizar_estagio(){
	int limite  = sprite.size();
	estagio++;
	if (estagio == limite ) estagio = 0;
}
