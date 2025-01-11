#include<iostream>
#include<string>

using namespace std;

class Classificavel{

    protected: 
        
        static int total_poligonos;

    public:
        
        Classificavel(){
            total_poligonos++;
        }
        
        ~Classificavel(){
        }

        virtual bool maiorQue(Classificavel outro) = 0;
};

int Classificavel::total_poligonos = 0;

class PolReg : public Classificavel{

    private:
        int lados;
        int tamanho;

    public:

        PolReg(){

        }
        

        ~PolReg(

        }

        bool maiorQue(Classificavel outro) override
        {

            
        }
};


class TriEq : public Classificavel{

    private:
        int lados;
        int tamanho;

    public:

        TriEq(){

        }
        

        ~TriEq(

        }

        bool maiorQue(Classificavel outro) override
        {

            
        }
};

class Quad : public Classificavel{

    private:
        int lados;
        int tamanho;

    public:

        Quad(){

        }
        

        ~Quad(

        }

        bool maiorQue(Classificavel outro) override
        {

            
        }
};

class Principal{

    private:
        PolReg pol;
        TriEq tri;
        Quad quad;

    public:
        Principal():
        pol(), tri(), quad();
        {
            execucao();
        }
        ~Principal(){

        }

        void execucao()
        {
            cout << "Digite"

        }

};




int main(){

    

    return 0;
}