#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// Vec3b& pixel = img.at<Vec3b>(0, 0) (0, 0)위치의 픽셀 값 참고
// pixel[0] = blue, pixel[1] = green, pixel[2] = red

// Vec3b* ptr = img.ptr<Vec3b>(0) 
// ptr[0][0] == pixel[0]

void color_inverse() {
	Mat src = imread("butterfly.jpg", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			Vec3b& p1 = src.at<Vec3b>(j, i);
			Vec3b& p2 = dst.at<Vec3b>(j, i);

			p2[0] = 255 - p1[0];
			p2[1] = 255 - p1[1];
			p2[2] = 255 - p1[2];
		}
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	color_inverse();
}