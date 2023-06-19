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
		virtual vector<vector<char>> getSprite() = 0;
		virtual vector<vector<char>> getRSprite() = 0;
		int tamh, tamv;

};

class Sprite : public SpriteBase {

	public:
		Sprite (string arquivo);
		Sprite (vector<vector <char> >, int v, int h);//sobrecarga do construtor para sprite animado
		void Draw();
		vector<vector<char>> inline getSprite(){return sprite;}
		vector<vector<char>> getRSprite();
	private:
		vector<vector<char>> sprite;
};



class SpriteAnimado : public SpriteBase {

	public:
		SpriteAnimado (string arquivo, char sep);
		void atualizar_estagio();
		void Draw();
		vector<vector<char>> inline getSprite()
		{
			vector<vector<char>> a = sprite[estagio].getSprite();
			atualizar_estagio();
			return a;
		}
		vector<vector<char>> inline getRSprite()
		{
			vector<vector<char>> a = sprite[estagio].getRSprite();
			atualizar_estagio();
			return a;
		}
	private:
		int estagio;
		vector<Sprite> sprite;
};

#endif
