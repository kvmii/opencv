#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// cvtColor -> 색변환 함수

void color_grayscale() {
	Mat src = imread("butterfly.jpg");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	color_grayscale();
}