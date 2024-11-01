#include<iostream>

using namespace std;


float f(int t, int y){

	return (2 * t - y + 1);


}

int main(){

	// Defina f(t,y)

	// Alimente com valores iniciais t e y0
	
	int t0, y0;
	cout << "Digite t0 e y0: " << endl;
	cin >> t0 >> y0;

	f(t0,y0);

	// Alimente o tamanho do passo e o numero de passos n
	
	int n;
	cout << "Digite o número de passos n" << endl;
	cin >> n;

	//escreva t0 e y0

	
	float y=0, k1=0, t=0, h=0;

	// para j de 1 até n calcule
	
	for(int j=0; j<n; j++){
	
		// k1 = f(t,y)
		k1 = f(t,y);

		// y = y+h * k1
		y = y + h * k1;

		// t = t + h
		t = t+h;
		
	}
	// escreva t e y
	cout << "t = " << t << " y = " << y << endl;
	
	// fim
	
	return 0;
}
