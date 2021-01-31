#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void sovel_edge() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dx, dy;
	Sobel(src, dx, CV_32FC1, 1, 0);
	Sobel(src, dy, CV_32FC1, 0, 1);
	// sobel mask

	Mat fmag, mag;
	magnitude(dx, dy, fmag);
	//magnitude(I) = sqrt(pow(x(I), 2) + pow(y(I), 2))

	fmag.convertTo(mag, CV_8UC1);
	// fmag�� grayscale�������� ��ȯ�Ͽ� mag�� ����

	Mat edge = mag > 150;
	// ���� �Ǻ��� ���� �׷����Ʈ ũ�� �Ӱ谪�� 150���� ����.
	// mag��� ���Ұ��� 150���� ũ�� 255, ������ 0���� ����

	imshow("src", src);
	imshow("mag", mag);
	imshow("edge", edge);

	waitKey();
	destroyAllWindows();
}
