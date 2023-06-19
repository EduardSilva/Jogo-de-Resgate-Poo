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



vector<vector<char>> Sprite:: getRSprite(){

	bool controle;
	vector<vector<char>> retorno;
	int ponta;
	
	for (int i = 0; i < tamv; i++){
	
		int limite = sprite[i].size();
		vector<char> linha;
		controle = false;
		ponta = 0;
		
		for(int j = 0; j < limite; j++, ponta++){//pega os epaços e verifica se precisa inverter a linha
		
			if(sprite[i][j] == 0x7) controle = true;
			
			if(sprite[i][j] != ' ' && !controle ) break;
			
			linha.push_back(sprite[i][j]);
		}
		
		for (int k = limite-1; k > ponta; k--){
			linha.push_back(sprite[i][k]);
		}
		retorno.push_back(linha);
	}

	return retorno;
}


void Sprite::Draw(){
	for (int v = 0; v < this->tamv; v++){
		int taml =  this->sprite[v].size();
		for(int h = 0; h <taml; h++){
				cout << this->sprite[v][h];
			}
		cout << std::endl;
	}//refatorado para melhor atualização.	
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
