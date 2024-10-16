
class Horario{

	private:
		int hora;
		int min;

	public:
		// Construtor/Destrutor
		Horario(int hr = 12, int mn = 0); // Construtor c Parâmetro
		~Horario();
		int getHora();
		int getMin();
		void setHora(int h);
		void setMin(int m);
		int calcularIntervalo(Horario h);

};
