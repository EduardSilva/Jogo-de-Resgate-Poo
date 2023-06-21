#include "../headers/Obj_de_Jogo.hpp"


Obj_de_Jogo::Obj_de_Jogo(int x, int y, int prioridade, bool estado, SpriteBase &sprite )
	:x(x), y(y), prioridade(prioridade), ativo(estado){
	//inserção do sprite.
	this->sprite = &sprite;
	//criação da box de colisão.
	this->box[0] = this->sprite->tamv - 1;
	this->box[1] = this->sprite->tamh - 1;
}

void Obj_de_Jogo::update(){
	this->box[0] = this->sprite->tamv - 1;
	this->box[1] = this->sprite->tamh - 1;
	
}

void Obj_de_Jogo::mover_se(int x, int y, bool incrementar){
	if (incrementar){
		this->x += x;
		this->y += y;
		return;
	}

	this->x = x;
	this->y = y;
	return;
}

bool Obj_de_Jogo::colidindo_com(const Obj_de_Jogo &outro)const{
	if (!this->esta_ativo() || !outro.esta_ativo()) {
	        return false;
	    }
	// Verificar colisão vertical
    bool colisao_horizontal = (this->x < outro.x + outro.box[0]) && (this->x + this->box[0] > outro.x);
    
    // Verificar colisão horizontal
    bool colisao_vertical = (this->y < outro.y + outro.box[1]) && (this->y + this->box[1] > outro.y);
    
    // Verificar colisão total
    return colisao_horizontal && colisao_vertical;
}

//referente a Helicoptero

Helicoptero::Helicoptero(int x, int y, int prioridade, bool ativo, SpriteBase &sprite): 
Obj_de_Jogo(x, y, prioridade, ativo, sprite), gasolina(300), peso(0)
{
	//nada.
};

int Helicoptero::pegarPessoa(Pessoa & p){

	if(! p.esta_ativo() || p.getPeso() + peso > 300 || pessoas.size() ==4){
		return -1;
	}
	pessoas.push_back(&p);
	p.trocar_modo();
	attPeso(p.getPeso(), false);
	return 1;
	
}

void Helicoptero::update(){
	this->box[0] = this->sprite->tamv - 1;
	this->box[1] = this->sprite->tamh - 1;
	int quant = pessoas.size();
	attGasolina(1*quant, true);
	
}

void Helicoptero::soltarPessoas(int x, int y){
	int l = y;
	for (Pessoa* &p : pessoas) {
        p->mover_se(x, l, false);
        p->trocar_modo();
        l += 3;
    }
    pessoas.clear();
	
}


//referente a pessoa

Pessoa::Pessoa(int x, int y, int p, float pe, bool a, SpriteBase& s):
	Obj_de_Jogo(x,y,p,a,s), peso(pe)
	{
		//nada
	}
