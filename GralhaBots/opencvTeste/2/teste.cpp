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
	A = imread("starry_night.jpg", IMREAD_COLOR);
	A.copyTo(C);
	/*
	for (int i = 0; i < 100; i++) {
        A.at<Vec3b>(i, 0)   = Vec3b(b, g, r); // lado esquerdo
        A.at<Vec3b>(i, 9)   = Vec3b(b, g, r); // lado direito
        A.at<Vec3b>(0, i)   = Vec3b(b, g, r); // topo
        A.at<Vec3b>(9, i)   = Vec3b(b, g, r); // base
	    }
	    */
	imshow("Display window", C);
	
	this_thread::sleep_for(std::chrono::milliseconds(10000));
	
	for(int j=0; j<10; j++){
		rectangle(A, Point(50+j, 50+j), Point(250, 250), Scalar(0, 255, 0), -1);
	}

	imshow("Display window", A);

	int k = waitKey(0); // Wait for a keystroke in the window

	if(k == 's')
	{
		imwrite("starry_night.png", A);
	}

	return 0;
}
