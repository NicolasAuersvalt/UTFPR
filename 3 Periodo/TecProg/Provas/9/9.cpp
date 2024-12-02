class Universo{

    private:
        GrupoEssenciais GE;
        Materia pM*;
        Antimateria pAM*;
        static const unsigned int carga_min;
        static const long int carga_max;

    public:
        Universo(): GE(), pM(NULL), pAM(NULL),
        {
            criarMaterias();
            criarAntimaterias();
            executar();
        }
        ~Universo(){
            if(pM) delete(pm);
            if(pAM) delete pAM
        }
        void criarMaterias(){
            for(int i=0; i<30000, i++){
                Materia *mat;
                mat->setCarga(i*5.5);
                mat->setNumero(i);
                mat->carga_minima(carga_min);
                GE.LMaterias.isert(mat);
            }

        }

        void criarAntimaterias(){
            for(int i=0; i< 1000, i++){
                pAm = new Antimateria;
                int rande = rand(-1,-30000)
                pAm->setNumero(rande)
                pAm->setCarga(rande)
                pAm->carga_maxima=i;



        }

        void executar(){
            GE.confrontarMateriaXAntimateria();


        }


}


int main(){

    Universo U;

    return 0;
}