#ifndef OBJ_DE_JOGO
#define OBJ_DE_JOGO

#include "Sprite.hpp"
#include <string>
	using std::string;
class Obj_de_Jogo {

	friend class Screen;
	
	public:
	//construtor 
	Obj_de_Jogo(int, int, int, bool, SpriteBase &);

	//Metodos genericos.
	void mover_se(int x, int y, bool incrementar);
	bool inline esta_ativo() const { return ativo; }
	void inline trocar_modo() { this->ativo = (!this->ativo); }
	int inline get_prioridade() const { return prioridade; }
	const int* get_box() const {return box;}
	bool colidindo_com(const Obj_de_Jogo & ) const;
	void draw() {sprite->Draw();}	
	void update();
	private:
	int x, y, prioridade;
	bool ativo;
	SpriteBase *sprite;
	int box[2];
};







#endif
