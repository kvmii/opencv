#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void hough_line_segments() {
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);
	
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat edge;
	Canny(src, edge, 50, 150);

	vector<Vec4i> lines;
	HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);
	// 선분의 최소길이, 직선으로 간주할 최대 에지 점 간격
	// 모든 직선의 시작점과 끝점 좌표를 구함

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (Vec4i l : lines) {
		line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}
