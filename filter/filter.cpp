#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void filter_embrossing();

int main() {
	filter_embrossing();
}

void filter_embrossing() {
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	float data[] = { -1,-1,0,-1,0,1,0,1,1 };
	Mat emboss(3, 3, CV_32FC1, data);

	Mat dst;
	filter2D(src, dst, -1, emboss, Point(-1, -1), 128);
	//filter2D(input, output, ddepth, filter, point(-1, -1) -> 커널 중심을 고정점, 더할 값)

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}