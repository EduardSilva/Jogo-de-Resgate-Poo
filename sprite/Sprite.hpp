#ifndef SPRITE
#define SPRITE
#include <vector>
	using std::vector;
#include <string>
	using std::string;
	
class SpriteBase {
	
	public:
		SpriteBase (string arquivo);
		virtual void Draw() =0;
			


	protected:
	vector<vector<char>> sprite;
	int tamh, tamv;
	char orientação;
};

class Sprite : public SpriteBase {

	public:
		Sprite (string arquivo) : SpriteBase(arquivo){
			//Nada pra se fazer no construtor.
		}
		void Draw();
	
};

#endif
