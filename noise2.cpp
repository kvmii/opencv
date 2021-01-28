#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void filter_bilateral() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, 5);
	add(src, noise, src, Mat(), CV_8U);

	Mat dst1;
	GaussianBlur(src, dst1, Size(), 5);

	Mat dst2;
	bilateralFilter(src, dst2, -1, 10, 5);
	// 색공간, 좌표공간, 가장자리 픽셀 방식
	// 양방향 필터
	// 가우시안 필터는 잡음을 줄이면서 에지도 함께 줄인다

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	
	waitKey();
	
	destroyAllWindows();
}

int main() {
	filter_bilateral();
}