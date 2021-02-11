#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void hough_circles() {
	Mat src = imread("coins.png", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat blurred;
	blur(src, blurred, Size(3, 3));

	vector<Vec3f> circles;
	// 원의 좌표(a,b)와 반지름 r이 차례대로 저장
	HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);
	// 원 검출

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (Vec3f c : circles) {
		Point center(cvRound(c[0]), cvRound(c[1]));
		// x, y
		int radius = cvRound(c[2]);
		// r
		circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	hough_circles();
}