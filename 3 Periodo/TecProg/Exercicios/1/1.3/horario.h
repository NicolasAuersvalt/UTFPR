
class Horario{

	private:
		int hora;
		int min;

	public:
		// Construtor/Destrutor
		Horario(int hr = 20, int mn = 30); // Construtor c Parâmetro
		~Horario();
		int getHora();
		int getMin();
		void setHora(int h);
		void setMin(int h);
		int calcularIntervalo(Horario h);

};
