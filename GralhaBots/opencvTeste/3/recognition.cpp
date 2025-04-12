#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// remover
#include <chrono>
#include <thread>

#include <iostream>

using namespace cv;
using namespace std;

class ImageManipulation{

	private:
		Mat A;

	public:
		ImageManipulation(string location){
			if(!location.empty())
				A = imread(location, IMREAD_COLOR);
		}
		~ImageManipulation(){
		}
		void imageResize(int proportion){
			if(A.empty()) {
				cout << "error: empty matrix." << endl;
				return;
			}
			Mat B;
			int x, y;

			// Testar float (ESTÁ IMPERFEITO)
			x = A.cols * proportion/1000;
			y = A.rows * proportion/1000;

			resize(A, B, Size(x,y));
			A = B;
		}

		void bwFilter(){
			if(A.empty()){
				cout << "error: empty matrix." << endl;
				return;
			}
			Mat B;
			cvtColor(A,B,COLOR_BGR2GRAY);
			A = B;
		}
		void process(){
			// pega o ponto central
			int midX = A.rows / 2;

			// Pega os valores limites
			pair<int, int> limites;
			limites = findLimits(midX);
				
		}

		// CONCLUIR LÓGICA COM DENSIDADE
		pair<int,int> findLimits(int mid){
			// Função vai considerar a densidade de pontos
			// então tira uma média desses pontos

			int densEsq=0, densDir=0;
			// pega à esquerda
			for(int i=mid; i>0; i--)
			{

			}
			

			// pega à direita
		}
		void show()
		{	
			if(A.empty()){
				cout << "error: empty matrix." << endl;
				return;
			}
			imshow("Display window", A);
			waitKey(0);

		}


};

int main(int argc, char** argv)
{
	ImageManipulation Image("1.png");

	// redimensiona para a proporção x
	Image.resize(50); // 50% do tamanho original

	// transforma em preto e branco
	Image.bwFilter();
	
	// pega o ponto central e verifica à esquerda e à direita para pegar as bordas
	Image.process();
	

	return 0;
}
