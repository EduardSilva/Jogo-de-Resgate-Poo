#include "../headers/setups.hpp"



Fase1 & setupf1(Fase1 &f){
	static Sprite init("--Iniciar",9);
	static Sprite exit("--Sair",6);
	static Sprite set(">", 1);
	
	static Obj_de_Jogo iniciar(15,78,0,true, init);
	static Obj_de_Jogo sair(20,78,1,true,exit);
	static Obj_de_Jogo seta (15,78,2,true, set);
	
	f << iniciar << seta << sair;


	
	return f;
};

Fase2 & setupf2(Fase2 &f){
	static SpriteAnimado helis("../sprites/Heli.txt");
	static SpriteAnimado p1 ("../sprites/Pessoa.txt");
	static SpriteAnimado p2 ("../sprites/Pessoa.txt");
	static SpriteAnimado p3 ("../sprites/Pessoa.txt");
	static SpriteAnimado p4 ("../sprites/Pessoa.txt");
	static SpriteAnimado p5 ("../sprites/Pessoa.txt");
	static Sprite predio1s ("../sprites/predio1.txt");
	static Sprite predio2s ("../sprites/predio2.txt");
	static Sprite predio3s ("../sprites/predio3.txt");

	static Obj_de_Jogo predio1(22, 3, 0, true,predio1s);
	static Obj_de_Jogo predio2(24, 53, 1, true,predio2s);
	static Obj_de_Jogo predio3(20, 120, 2, true,predio3s);
	static Pessoa pessoa1(31, 8, 4, 54.2, true, p1);
	static Pessoa pessoa2(31, 34, 5, 00.2, true, p2);
	static Pessoa pessoa3(31, 55, 6, 50.2, true, p3);
	static Pessoa pessoa4(31, 80, 7, 50.2, true, p4);
	static Pessoa pessoa5(31, 110, 8, 50.2, true,p5);
	static Helicoptero heli (2, 4, 10,true, helis);
	f << predio1 << predio2 << predio3 << pessoa1 << pessoa2 << pessoa3
		<< pessoa4 << pessoa5;

	f.setHeli(heli);
	return f;
}

Fase3& setupf3(Fase3& f){
	static Sprite init("--Você venceu!--",17);
	static Obj_de_Jogo iniciar(15,78,0,true, init);
	f<<iniciar;

	return f;
}

Fase4& setupf4(Fase4& f){
	static Sprite init("--Você perdeu!--",17);
	static Obj_de_Jogo iniciar(15,78,0,true, init);
	f<<iniciar;

	return f;
}
