#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){

	vector<float> vet(5,0);
	for(int i=0; i<5; i++){
		cin >> vet[i];
	}
	float media;
	for(int i=0; i<5; i++){
		media+=vet[i];
	}
	media /=5.0;
	float desvio =0;
	for(int i=0; i<5; i++){
		desvio += (vet[i] - media) * (vet[i] - media) / 5;
//		cout << desvio << endl;
	}
	cout << sqrt(desvio);
	return 0;	

}
