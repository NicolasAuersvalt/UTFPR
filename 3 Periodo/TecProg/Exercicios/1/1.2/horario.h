
class Horario{

	private:
		int hora;
		int min;

	public:
		// Construtor/Destrutor
		Horario();
		~Horario();
		int getHora();
		int getMin();
		void setHora(int h);
		void setMin(int h);
		int calcularIntervalo(Horario h);

};
