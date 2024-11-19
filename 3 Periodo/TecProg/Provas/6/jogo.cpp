#include<iostream>

using namespace std;

// Deve ser declarado aqui pois será agregado
class Personagem{

    protected:
        int x;
        const static int MAX;

    public:
        Personagem(const int _x):
            x(_x),
            MAX(20) // Deve ter o valor 20
            {

            }
        virtual ~Personagem(){
            x = 0;
        }
    
        const int getX()
        {
            return x;
        }
        
        const int getMAX()
        {
            return MAX;
        }
        
        virtual void movimentar() = 0; // Pois a classe é abstrata

};

class Curupira : public Personagem{ // declara-se antes de BoiTata

    private:
        bool empoderado;
        bool avancar;
        int nvidas;

    public:
        Curupira(const int emp, const int _x)) : empoderado(emp),
        avancar(_x), nvidas(MAX) {
        }
        ~Curupira(){
            empoderado = false;
            avancar = false;
            nvidas = -1;
        }

        const bool getEmpoderado(){
            return empoderado;
        }

        const int getNvidas(){
            return nvidas
        }
        void setNvidas(const int nv){
            nvidas = nv;
        }
        void movimentar(){
            if(avancar){
                while(x<MAX){
                    x++
                }
            }
            else{
                while(x>0){
                    x--;
                }
            }
        }    
};


class BoiTata: public Personagem{

    private:
        int energia;
        Curupira* pCurupira;

    public:
    BoiTata(Curupira *pCur, const int energ, const int _x): energia(energ),
    pCurupira(pCur),
    {
    }
    ~BoiTata(){
        pCur = nullptr;

    }
    const int getEnergia(){
        return energia;
    }
    void atacar(){
        // Deve atacar somente UM curupira
        
        // Se estiverem na mesma posição
        if(x == (*pCurupira)->x){
            // Se sim, verifica se está empoderada
            if((*pCurupira)->empoderado){
                // Se sim, decrementa a energia de Botata

                energia-=0.1*(*pCurupira)->nvidas // decrementa 10% da vida de curupira
            }
            else{
                energia+=0.1*(*pCurupira)->nvidas // incrementa 10% da vida de curupira
                nvidas -= energia;
            }
                
                // Se não, é incrementada e as nvidas é decrementada
            }
        }
    }


};


class VetorPersonagens{

    private:
    // Agregação fraca pois o personagem existe independentemente do vetor
        list<Personagem*> personagens;
        list<Personagem*> :: iterator itPersonagens

    public:
        VetorPersonagens(){
            Personagem(nullptr),
            itPersonagens(nullptr)
        }
        ~VetorPersonagens(){
            Personagem = nullptr;
            itPersonagens = nullptr;
        }

        void inserir(Personagem* p){
            if(p){
                personagens.push_back(p);
            }
        }

        Personagem* operator [](const int idx){
            auto it = personagem.begin()
            for(int i=0; i<idx; i++){
                it++;
            }
            return it;
        }

        Personagem* excluir(int idx){
            return personagem.remove(idx);
        }

};


class Jogo{

    private:
        int quant_bt;
        VetorPersonagens vetPers;
    
    public:
        Jogo(const int qbt) : quant_bt(qbt){
            // Cria personagens
            Curupira *fulanodetal(rand(), true);
            (*fulanodetal)->nvidas = rand()%100;
            vetPers.push_back(*fulanodetal);

            for(int i=0; i<qbt; i++){

                // Agregação forte
                BoiTata *fulano;
                vetPers.push_back(fulano);
            }
            // Coloca no vetor de personagens
        }
        ~Jogo(){
            for(auto it = vetPers.begin(); it!- vetPers.end(); it++){

                remove it;
            }
        }

        void executar(){

            // Executa ações do jogo

        }
}


int main(){

    Jogo jogo(3);


    return 0;

}