#ifndef OBJ_DE_JOGO
#define OBJ_DE_JOGO

#include "Sprite.hpp"
#include <string>
	using std::string;
#include <list>
	using std::list;
class Obj_de_Jogo {

	friend class Screen;
	
	public:
	//construtor 
	Obj_de_Jogo(int, int, int, bool, SpriteBase &);

	//Metodos genericos.
	virtual void mover_se(int x, int y, bool incrementar);
	bool inline esta_ativo() const { return ativo; }
	void inline trocar_modo() { this->ativo = (!this->ativo); }
	int inline get_prioridade() const { return prioridade; }
	int get_boxH() const {return box[1];}
	int get_boxV() const {return box[0];}
	const int * get_box() const{return box;}
	int getx() {return x;}
	int gety() {return y;}
	bool colidindo_com(const Obj_de_Jogo & ) const;
	void draw() {sprite->Draw();}	
	void update();
	protected:
	int x, y, prioridade;
	bool ativo;
	SpriteBase *sprite;
	int box[2];
};

class Pessoa : public Obj_de_Jogo {
	friend class Screen;
	public:
	Pessoa(int, int, int, float, bool, SpriteBase&);
	float getPeso()const 
	{
		return peso;
	}
	private:
	float peso;

	
};

class Helicoptero : public Obj_de_Jogo{
	friend class Screen;

	public:
	Helicoptero(int, int, int, bool, SpriteBase&);
	float getPeso() const
	{
		return peso;
	}
	float getGasolina() const
	{
		return gasolina;
	}
	void attPeso(float p, bool reduce){
		if (reduce) peso -= p;
		else peso += p;
	}
	void attGasolina(float g, bool reduce)
	{
		if (reduce) gasolina -=  g;
		else gasolina += g;
	}
	void update();
	int pegarPessoa(Pessoa &);
	void soltarPessoas(int, int);
	
	private:
	float gasolina, peso;
	list<Pessoa *> pessoas;
};

#endif
