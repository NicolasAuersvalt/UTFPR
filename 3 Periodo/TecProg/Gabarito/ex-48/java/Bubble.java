public class Bubble <T extends ClasseQualquer>{
    private T[] objetos;
    
    Bubble(T[] objetos){
        this.objetos = objetos;
    }

    private void trocaObjetos(final int pos1, final int pos2){
        T objetoAux = objetos[pos1];
        objetos[pos1] = objetos[pos2];
        objetos[pos2] = objetoAux;
    }

    void classifica(){
        int posFinal = objetos.length;
        while(posFinal - 1 > 0){
            for(int j = 0; j < posFinal - 1; j++){
                ClasseQualquer obj1 = objetos[j];
                ClasseQualquer obj2 = objetos[j + 1];
                if(obj1.maiorQue(obj2)){
                    trocaObjetos(j, j + 1);
                }
            }
            posFinal--;
        }
    }
}
