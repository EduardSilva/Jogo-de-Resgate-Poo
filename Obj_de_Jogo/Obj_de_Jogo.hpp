#ifndef OBJ_DE_JOGO
#define OBJ_DE_JOGO

#include "../sprite/Sprite.hpp"
#include <string>
	using std::string;
class Obj_de_Jogo {

	friend class Screen;
	
	public:
	//construtor 
	Obj_de_Jogo(int, int, int, char, bool, SpriteBase &);

	//Metodos genericos.
	void mover_se(int x, int y, bool incrementar);
	bool inline esta_ativo() const { return ativo; }
	void inline trocar_modo() { this->ativo = (!this->ativo); }
	int inline get_prioridade() { return prioridade; }
	bool colidindo_com(const Obj_de_Jogo & ) const;
	void draw() {sprite->Draw();}	

	private:
	int x, y, prioridade;
	bool ativo;
	SpriteBase *sprite;
	char orientação;
	int box[2];
};







#endif
