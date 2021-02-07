#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void contrast2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	float alpha = 1.f;
	Mat dst = src + (src - 128) * alpha;
	// 효과적인 명암비 - dst(x,y) = src(x,y) + (src(x,y) - 128) * a

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	contrast2();
}