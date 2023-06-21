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
		int tamh, tamv;
		

};

class Sprite : public SpriteBase {

	public:
		Sprite (string arquivo);
		Sprite (string texto, int tam):sprite(1,vector<char>(tam, ' ')){
			for (int i =0; i<tam; i++){
				sprite[0][i] = texto[i];
			}
		}
		Sprite (vector<vector <char> >, int v, int h);//sobrecarga do construtor para sprite animado
		void Draw();
		vector<vector<char>> inline getSprite(){return sprite;}
	private:
		vector<vector<char>> sprite;
};



class SpriteAnimado : public SpriteBase {

	public:
		SpriteAnimado (string arquivo, char sep= 0x7);
		void atualizar_estagio();
		void Draw();
		vector<vector<char>> inline getSprite()
		{
			vector<vector<char>> a = sprite[estagio].getSprite();
			atualizar_estagio();
			return a;
		}
		
	private:
		int estagio;
		vector<Sprite> sprite;
};

#endif
