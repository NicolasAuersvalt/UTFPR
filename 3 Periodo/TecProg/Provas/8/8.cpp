// 1 - Base OK

// 2 - Constelacao OK

// 3 - BuracoGravitacional

// 4 - Zona Gravitacional

// 5 - Galaxia

#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<string>

using namespace std;

class Ente{

    protected:
        int mass;

    public:
        Ente(){}
        virtual ~Ente(){}           // 1
        void setMassa(const int m){
            mass = m;
        }
        const int getMassa(){
            return massa;
        }
        virtual void operator--() = 0; // virtual puro
        void operator++(){
            mass++;
        }
};

class Constelacao():public Ente(){

    private:
        int distancia_buraco;

    public:
        Constelacao(): distancia_buraco(-1){}
        ~Constelacao(){}
        void setDistanciaBuraco(const int DB){
            if(DB >= 0){
                distancia_buraco = DB;
            }
        }
        const int getDistanciaBuraco(){
            return distancia_buraco;
        }
        void operator--() override{
            if (distancia_buraco>0)
                distancia_buraco--;
        }
}

// Declara a zona gravitacional
class ZonaGravitacional;

class BuracoGravitacional():public Ente{
    private:
        ZonaGravitacional GB;
        ZonaGravitacional GC;

    public:
        BuracoGravitacional():GB(), GC(){}
        BuracoGravitacional(){}
        void operator=(Buraco_Gravitacional* pGB){
            if(pGB)
                GB = pGB;
        }
        void operator=(Constalacao* pC){
            if(pC)
                gC = pC;
        }
        void executar(){}
}   


class Principal{
    private:
        ZonaGravitacional GZ;
        Constelacao* pAuxC;
        BuracoGravitacional *pMaior, *pMedio, *pMenor;

    public:
        Principal():GZ(), pAuxC(NULL), 
        pMaior(NULL), pMedio(NULL), pMenor(NULL){
            criarBuracosGravitacionais();
            criarConstelacoes();
            executar();
        }
        ~Principal(){
            if(pMaior) delete pMaior;
            if(pMedio) delete pMedio;
            if(pMenor) delete pMenor;
        }
        void criarBuracosGravitacionais(){
            pMaior = new BuracoGravitacional;
            pMedio = new BuracoGravitacional;
            pMenor = new BuracoGravitacional;

            pMaior->setMassa(100);
            pMedio->setMassa(50);
            pMenor->setMassa(5);

            criarConstelacoes();
        }
        void criarConstelacoes(){
            
            for(int i=0; i<100; i++){
                pAuxC = new Constelacao;          

                pMaior->setDistancia(i+1);

                pMaior->setMassa(10*i);

                pMaior->operator=(pAuxC);
            }

            executar();
        }
        void executar(){
            if(pMaior){
                pMaior->executar();
            }
        }
}

int main(){
    Galaxia FiatLux;
    return 0;

}