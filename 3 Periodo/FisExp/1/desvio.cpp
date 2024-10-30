#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
	int a;
	cin >>a;
	vector<float> vet(a,0);
	for(int i=0; i<a; i++){
		cin >> vet[i];
	}
	float media;
	for(int i=0; i<a; i++){
		media+=vet[i];
	}
	media /= (float) a;
	float desvio =0;
	for(int i=0; i<a; i++){
		desvio += (vet[i] - media) * (vet[i] - media) / a;
//		cout << desvio << endl;
	}
	cout << sqrt(desvio);
	return 0;	

}
