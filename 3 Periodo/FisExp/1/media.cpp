#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){

	vector<float> vet(5,0);
	for(int i=0; i<5; i++){
		cin >> vet[i];
	}
	float media=0;
	for(int i=0; i<5; i++){
		media+=vet[i];
	}
	media /=5.0;
	
	cout << "media: " << media << endl;
	return 0;	

}
