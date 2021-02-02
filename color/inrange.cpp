#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// inrange를 이용하여 특정 색상 영역 추출

int lower_hue = 40, upper_hue = 80;
Mat src, src_hsv, mask;

void on_hue_changed(int, void*);

int main(int argc, char* argv[]) {
	src = imread("candies.png", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	cvtColor(src, src_hsv, COLOR_BGR2HSV);

	imshow("src", src);

	namedWindow("mask");
	createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
	createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
	on_hue_changed(0, 0);

	waitKey();
	return 0;
}

void on_hue_changed(int, void*) {
	Scalar lowerb(lower_hue, 100, 0);
	Scalar upperb(upper_hue, 255, 255);
	inRange(src_hsv, lowerb, upperb, mask);
	// 범위 안에 있으면 흰색, 아니면 검은색으로 표현
	imshow("mask", mask);
}
