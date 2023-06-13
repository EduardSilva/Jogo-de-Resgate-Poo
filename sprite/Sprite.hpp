#ifndef SPRITE
#define SPRITE
#include <vector>
	using std::vector;
#include <string>
	using std::string;
	
class SpriteBase {
	
	public:
		SpriteBase (){
			//Fazer um belissimo nada.
		}
		virtual void Draw() =0;

		int tamh, tamv;

};

class Sprite : public SpriteBase {

	public:
		Sprite (string arquivo);
		Sprite (vector<vector <char> >, int v, int h);//sobrecarga do construtor para sprite animado
		void Draw();
	private:
		vector<vector<char>> sprite;
};



class SpriteAnimado : public SpriteBase {

	public:
		SpriteAnimado (string arquivo, char sep);
		void atualizar_estagio();
		void Draw();
	private:
		int estagio;
		vector<Sprite> sprite;
};

#endif
