#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void brightness1() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst = src + 100;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

