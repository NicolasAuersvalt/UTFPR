#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>
#include <thread>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	int b = 0, g = 0, r = 255;
	Mat A, C;
	A = imread("1.png", IMREAD_COLOR);
	A.copyTo(C);

	Vec3b cor = A.at<Vec3b>(100, 200);

	int largura = A.cols;
	int altura = A.rows;

	int ksize = 50; // tamanho do kernel
	Mat kernel = Mat::ones(ksize, ksize, CV_32F) / (float)(ksize * ksize); // kernel
	
	for (int y = offset; y < imagem.rows - offset; y++) {
 	       for (int x = offset; x < imagem.cols - offset; x++) {

	/*
	for(int i= largura/3; i < ((largura/3)+(largura/3)); i++){
		Vec3b cor = A.at<Vec3b>(altura/8, i);
		if (cor[0] == 0 && cor[1] == 0 && cor[2] == 0) {
		    cout<< "Fora da linha i = " << i <<endl;
		}	
	}
	*/
	
	imshow("Display window", C);

	return 0;
}

