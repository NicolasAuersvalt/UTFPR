#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Personagem{ // abstrata

    private:
        string nome;

    public:

        Personagem(){
            nome.erase();
        }
        ~Personagem(){
            nome.erase();
        }

        virtual void mover()= 0;

        void setNome(string nome){
            this->nome = nome;
        }

        const string getNome() const{
            return nome;
        }


};

class Jogador: public Personagem{

    protected:
        int vidas;

    public:

        Jogador()
        {
            vidas = 0;
            setNome("Jogador");
        }
        ~Jogador(){
            vidas = 0;
        }

        virtual void mover() override
        {
            cout << getNome() << " movendo" << endl;
        }

        void setVidas(int vidas){
            this->vidas = vidas;
        }
        int getVidas(){
            return vidas;
        }

};


class Protetor : public Personagem{

    protected:
        float energia;

    public:

        Protetor(): energia(0.0){

        }
        virtual ~Protetor(){
            energia = 0.0;
        }
        virtual void mover() = 0;
        void setEnergia(float energia){
            this->energia = energia;
        }
        float getEnergia(){
            return energia;
        }

};

class Inimigo : public Personagem{

    protected:
        bool ativo;

    public:

        Inimigo(){
            ativo = true;
        }
        ~Inimigo(){
            ativo = false;
        }

        virtual void mover() = 0;

        void setAtivo(bool ativo){
            this->ativo = ativo;
        }
        bool getAtivo(){
            return ativo;
        }

};

class Curupira : public Protetor{

    private:
        vector<Personagem*> vetorPersonagem;

    public:
        Curupira(){
            setNome("Curupira");
            vetorPersonagem.clear();
        }

        ~Curupira(){
            vetorPersonagem.clear();
        }

        virtual void mover() override{
            cout << getNome() << " Movendo um passo" << endl;
        }
        void proteger_todos(){
            cout << "A fazer" << endl;
        }
};


class Fada : public Protetor{

    private:
        Jogador* pJog;

    public:
        Fada(): pJog(nullptr){
            setNome("Fada");
        }
        ~Fada(){

        }

        void mover() {
            cout << getNome() << " Movendo um passo" << endl;
        }

        void proteger_jogador(){
            cout << "A fazer" << endl;
        }

        void setJogador(Jogador *pJog){
            if(pJog){
                this->pJog = pJog;
            }
        }
};

class BoiTata : public Inimigo{
    private:
        float poder_fogo;
        Jogador* pJog;

    public:

        BoiTata() : pJog(nullptr){
            poder_fogo = 0;
            setNome("BoiTata");
        }
        ~BoiTata(){
            poder_fogo = 0;
        }

        virtual void mover() override{
            cout << getNome() << " Movendo um passo" << endl;
        }

        void enviar_fogo(){
            cout << "A fazer" << endl;
        }

        BoiTata operator++(){
            poder_fogo++;
        }

        void setJogador(Jogador *pJog){
            if(pJog){
                this->pJog = pJog;
            }
        }
};

class Pilha_Personagens{

    private:
        vector<Personagem*> vetorPersonagem;

    public:
        Pilha_Personagens()
        {
            vetorPersonagem.clear();
        }

        ~Pilha_Personagens(){
            vetorPersonagem.clear();
        }

        void empilhar(Personagem* ps){
            if(ps){
                if(vetorPersonagem.size()<10){
                    vetorPersonagem.push_back(ps);
                }
            }
        }
        void desempilhar(){
            int tam = vetorPersonagem.size();
            while(tam > 0){
                vetorPersonagem[tam-1]->mover();
                vetorPersonagem[tam-1] = nullptr;
                tam--;
            }
        }
    
};


class Jogo{

   private:

    Pilha_Personagens pilha;


    public:

        Jogo(): pilha()
        {

        }
        ~Jogo(){

        }

        void incluir_personagem(Personagem* pe){
            if(pe){
                pilha.empilhar(pe);
            }
        }

        void listar(){
            pilha.desempilhar();
        }


};


int main(){
    Jogo Brasileirinho;

    Curupira* curupira = new Curupira();
    BoiTata* boitata = new BoiTata();
    Jogador* jogador = new Jogador();
    Fada* fada = new Fada();

    
    Brasileirinho.incluir_personagem(curupira);
    Brasileirinho.incluir_personagem(boitata);
    Brasileirinho.incluir_personagem(jogador);
    Brasileirinho.incluir_personagem(fada);

    Brasileirinho.listar();


    delete curupira;
    delete boitata;
    delete jogador;
    delete fada;

}