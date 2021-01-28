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
	// ������, ��ǥ����, �����ڸ� �ȼ� ���
	// ����� ����
	// ����þ� ���ʹ� ������ ���̸鼭 ������ �Բ� ���δ�

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	
	waitKey();
	
	destroyAllWindows();
}

int main() {
	filter_bilateral();
}