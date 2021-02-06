#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void brightness2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			int v = src.at<uchar>(i, j) + 100;
			dst.at<uchar>(i, j) = v > 255 ? 255 : v < 0 ? 0 : v;
			// 255�� �Ѿ ��� 255, 0���� ������ ��� 0���� ����
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}

int main() {
	brightness2();
}
