#include<iostream>
#include<set>
#include<list>

using namespace std;

class Cidadao{

    protected:

        static int cont_id;
        int id;

    public:
        Cidadao()
        id(cont_id)
        {
        }
        virtual ~Cidadao()
        {
            id = -1;
        }

        virtual void votar() = 0;
        
        virtual void desalienar() = 0;

        const virtual int getLimpo() = 0;

        const int getId()
        {
             return id;
        }
};

int Cidadao::cont_id(0);

int Candidato::votos_total(0);

class Eleitor : public Cidadao{

    protected:
        bool alienado;
        set<candidato*> cands;
        const int limpo;

    public:
        Eleitor():
        Cidadao(),
        alienado((bool)(rand()%2)),
        cands(),
        limpo(100)
        {
            cands.clear();
        }
        ~Eleitor()
        {
            cands.clear();
        }
        virtual void votar()
        {
            set<Candidato*>::iterator atual;
            float chance=0;

            for(atual = cands.begin(); atual != cand.end(); ++atual){
                
                if(alienado){ // 10% de chance
                    chance += 0.1;

                }
                else{

                }   
            }
            delete atual;

        }
        virtual const int getLimpo()
        {
            return limpo;
        }
        void desalienar()
        {
            alienar = false;
        }
        void considerar(Candidato* p)
        {
            // Testa ponteiro
            if(p)
            {
                cands.insert(p);
            }
            else{
                cout << "Erro" << endl;

            }
        }



};

class Candidato : public Eleitor{

    private:
        static int votos_total;
        int votos;
        int limpo;

    public:
        Candidato():
        Eleitor(),
        votos(0);
        limpo(rand()%100)
        {
        }
        ~Candidato(){

        }

        virtual void votar(){
            operator++;
        }

        const int getLimpo(){
            return limpo;
        }

        void operator++(){
            votos+=1;
            votos_total++;
        }
        
        const bool getEleito(){
            return votos > (votos_total/2) ? true : else;
            
        }


};

class Partido{

    private:
        list<Cidadao*> filiados; // > 5
    

    public:
        Partido(){
            filiados.clear();
        }
        ~Partido(){
            filiados.clear();
        }

        void filiar(Cidadao* p){
            if(p){
                filiados.push_back(p);
            }
            else{
                cout << "Erro" << endl;
            }
        }

        void desfiliar(Cidadao *p){
            if(p){
                filiados.remove(p);
            }
            else{
                cout << "Erro" << endl;
            }
        }
        void politizar(){

            list<Cidadao*> iterator atual;
            for(atual = filiados.begin(); atual != filiados.end(); atual++){
                (*atual)->desalienar();
            }
            delete atual;
        }


};

class Eleicao{

    private:
        vector<Eleitor*> eleitores; // > 20
        vector<Candidato*> candidatos; // > 3
        vector<Partido*> partidos; // > 2

    public:

        Eleicao():
            eleitores(),
            candidatos(),
            partidos()
        {
            eleitores.clear();
            candidatos.clear();
            partidos.clear();

            criarPartidos();
            criarEleitores();
            criarCandidatos();
            executar();
            }


        ~Eleicao(){
            

            eleitores.clear();
            candidatos.clear();
            partidos.clear();
            
        }
        void criarPartidos(){
            
        }
        void criarEleitores(){


        }
        void criarCandidatos(){

        }
        void executar(){


        }

};


int main(){




    return 0;
}