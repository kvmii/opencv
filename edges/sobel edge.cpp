#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void sovel_edge() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dx, dy;
	Sobel(src, dx, CV_32FC1, 1, 0);
	Sobel(src, dy, CV_32FC1, 0, 1);
	// sobel mask

	Mat fmag, mag;
	magnitude(dx, dy, fmag);
	//magnitude(I) = sqrt(pow(x(I), 2) + pow(y(I), 2))

	fmag.convertTo(mag, CV_8UC1);
	// fmag를 grayscale형식으로 변환하여 mag에 저장

	Mat edge = mag > 150;
	// 에지 판별을 위한 그래디언트 크기 임계값을 150으로 설정.
	// mag행렬 원소값이 150보다 크면 255, 작으면 0으로 설정

	imshow("src", src);
	imshow("mag", mag);
	imshow("edge", edge);

	waitKey();
	destroyAllWindows();
}
