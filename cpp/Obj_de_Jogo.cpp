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
