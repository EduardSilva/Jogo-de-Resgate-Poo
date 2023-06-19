#include "Obj_de_Jogo.hpp"


Obj_de_Jogo::Obj_de_Jogo(int x, int y, int prioridade, char orientação, bool estado,SpriteBase &sprite )
	:x(x), y(y), prioridade(prioridade), ativo(estado), orientação(orientação){
	//inserção do sprite.
	this->sprite = &sprite;
	//criação da box de colisão.
	this->box[0] = this->sprite->tamh - 1;
	this->box[1] = this->sprite->tamv - 1;
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

bool Obj_de_Jogo::colidindo_com(const Obj_de_Jogo &Other)const{
	//variaveis locais pra definir o espaço ocupado pelos objetos
	int txb = this->x + this->box[0];
	int tyb = this->y + this->box[1];
	
	int oxb = Other.x + Other.box[0];
	int oyb = Other.y + Other.box[1];

	bool xtouch, ytouch;
	xtouch = ( (this->x >= Other.x) && ( Other.x <= txb) ) || ( (Other.x >= this->x) && (this->x <=oxb ) );
	ytouch = ( (this->y >= Other.y) && ( Other.y <= tyb) ) || ( (Other.y >= this->y) && (this->y <=oyb ) );	

	if (xtouch ||  ytouch)
		return true;

	else
		return false;

	
}
