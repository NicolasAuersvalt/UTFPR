#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main(){

		vector<string> valores = {"0", "M_PI/6", "M_PI/4", "M_PI/3", "M_PI/2", "2*M_PI/3", "3*M_PI/4", "5*M_PI/6", "M_PI", "7*M_PI/6", "5*M_PI/4", "4*M_PI/3", "3*M_PI/2", "5*M_PI/3", "7*M_PI/4", "11*M_PI/6"};
		vector<double> vet = {0, M_PI/6, M_PI/4, M_PI/3, M_PI/2, 2*M_PI/3, 3*M_PI/4, 5*M_PI/6, M_PI, 7*M_PI/6, 5*M_PI/4, 4*M_PI/3, 3*M_PI/2, 5*M_PI/3, 7*M_PI/4, 11*M_PI/6};

		cout << "f(x) = sen(x)" << endl;

		for(int i=0; i<vet.size(); i++){
			cout << "f(" << valores[i] << ") = " <<  sin(vet[i]) << "   " << endl;
		}	
		cout << endl << endl;

		cout << "f(x) = 2 sen(x)" << endl;
		
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " <<  2 * sin(vet[i]) << "   " << endl;
		}

		cout << endl << endl;

		cout << "f(x) = 2 + sen(x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " <<  2 + sin(vet[i]) << "   " << endl;
		}	
		
		cout << endl << endl;

		
		cout << "f(x) = cos(x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << valores[i] << ") = " << + cos(vet[i]) << "   " << endl;
		}	

		cout << endl << endl;
	
		
		cout << "f(x) = 0.3 * sen(x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " <<  0.3 * sin(vet[i]) << "   " << endl;
		}	

		cout << endl << endl;

		
		cout << "f(x) = sen(x + M_PI/2)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " <<  sin(vet[i] + M_PI/2) << "   " << endl;
		}	

		cout << endl << endl;



		cout << "f(x) = sen(x - M_PI/2)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " <<  sin(vet[i] - M_PI/2) << "   " << endl;
		}	

		cout << endl << endl;
		
		
		cout << "f(x) =  sen^2(x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " << pow(sin(vet[i]), 2) << "   " << endl;
		}	

		cout << endl << endl;	

		cout << "f(x) =  cos^2(x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " << pow(sin(vet[i]), 2) << "   " << endl;
		}	
	
		cout << endl << endl;	
			
	
		cout << "f(x) =  sen(2x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " << sin(2 * vet[i]) << "   " << endl;
		}	
	
		cout << endl << endl;	
		
		
		cout << "f(x) =  sen(x/2)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " << sin(vet[i]/2) << "   " << endl;
		}	
	
		cout << endl << endl;	
	
		cout << "f(x) =  tg(x)" << endl;
		
		for(int i=0; i<vet.size(); i++){
			cout << "f(" << vet[i] << ") = " << tan(vet[i]) << "   " << endl;
		}	
	
		cout << endl;	


	return 0;
}
