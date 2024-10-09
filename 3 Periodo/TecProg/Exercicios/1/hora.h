#include <iostream>


class Horario{


	private:
		int hora;
		int min;	


	public:

		Horario(int a, int b){
			hora = a;
			min = b;
		}


		int get_Hora(){
			return hora;
		}

		int get_Min(){
			return min;
		}

		bool setHora(int newT){
			if(newT>=0){
				hora = newT;
				return true;
			}
			else{
				return false;
			}
		}

		int calcularIntervalo(Horario h){

			return h.hora-h.min;
		}

};
