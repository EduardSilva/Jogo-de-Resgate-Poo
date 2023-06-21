#include "../headers/Fase.hpp"
#include<iostream>


bool ordenar_objetos(const Obj_de_Jogo &a, const Obj_de_Jogo &b){

	return a.get_prioridade() < b.get_prioridade();
}


Fase::Fase(Screen &s){
	screen = &s;
}

Fase& Fase::operator<<(const Obj_de_Jogo & o){
	objetos.push_back(o);
	objetos.sort(ordenar_objetos);
	return *this;
}

Fase2 &Fase2::operator<<(const Obj_de_Jogo &o){
	objetos.push_back(o);
		objetos.sort(ordenar_objetos);
		return *this;
}

Fase2& Fase2::operator<<(const Pessoa & o){
	pessoas.push_back(o);
	pessoas.sort(ordenar_objetos);
	return *this;
}
void Fase2::show() 
	{ 
	Obj_de_Jogo * h = heli;
	system("clear");
	for (auto a : objetos) *screen << a;
	for (auto a : pessoas) *screen << a;
	*screen << *h;	
	screen->Draw();
	}


int Fase1::run(){


	char c = 'w';
    char p = 'u';
	show();
	 
    while ( c  !=  'x'  ) {
        if (c == 'w' && p != 'u') {
            objetos.back().mover_se(15, 78, false);
            p = 'u';
            show();
            
        }
        
        if (c == 's' && p != 'd') {
            objetos.back().mover_se(20, 78, false);
            p = 'd';
            show();
            
        }
        std::cin>>c;
        
    }

    if (p == 'u'){
    
        return 1;}
    else
        return -1;
}

void subir(Helicoptero *  h){
	if( h->getx() < 5) return; //não deixa subir mais
	h->mover_se(-3,0,true);
}
void descer(Helicoptero *  h){
	if (h->getx() + h->get_boxV() > 34) return;
	h->mover_se(2,0,true);
	std::cout<< h->getx() + h->get_boxV();
}

void mEsquerda(Helicoptero * h){

	if(h->gety() < 5 ) return;
	h->mover_se(0,-2,true);
}

void mDireita(Helicoptero * h){
	if (h->gety() + h->get_boxV() > 134) return;
	h->mover_se(0,2,true); 
	std::cout<< h->gety() + h->get_boxV();
}

void pegar(Helicoptero * h, list<Pessoa> &objetos){
	
	for (auto &i : objetos){
		std::cout<<h->colidindo_com(i);
		if(h->colidindo_com(i)){
			h->pegarPessoa(i);
			break;
		}
	}
	
}
void soltar(Helicoptero * h, Obj_de_Jogo & o){
	if (h->colidindo_com(o)) h->soltarPessoas(19,120);
}

bool winstatus(list<Pessoa> &p, Obj_de_Jogo & o ){
	for (auto &i : p) {
		if(i.colidindo_com(o)) {
		std::cout <<"colidiu";
		continue;}
		else return false;
		}
	return true;
}

int Fase2::run(){

	char c = 'r';
	bool kill = false;
 	auto it = objetos.begin();
    std::advance(it, 2);
    show();
	while (!kill){
		std::cin>>c;
		switch(c){
			case 'w':
                subir(heli);
                heli->update();
                break;
            case 's':
            	descer(heli);
            	heli->update();
            	break;
           	case 'a':
           		mEsquerda(heli);
           		heli->update();
           		break;
           	case 'd':
           		mDireita(heli);
           		heli->update();
           		break;
           	case 'x':
           		pegar(heli, pessoas);
           		heli->update();
           		break;
           	case 'z':
           		soltar(heli, (*it));
           		heli->update();
           		break;
        
		}	

	int gasolina = heli->getGasolina();
	int peso = heli->getPeso();
	int qpessoas = heli->getqPessoas();
	string a = " gasonlina : " + gasolina;
	a += " Peso : " + peso;
	a += " quantia p: " + qpessoas;

	Sprite b (a, a.size());
		*screen << Obj_de_Jogo(38, 14, 10, true, b);

	if(winstatus(pessoas, (*it)) ) return 2;
	show();
	if (heli->getGasolina() == 0 ) kill =true;
	
	}
	return -2;

		
}

