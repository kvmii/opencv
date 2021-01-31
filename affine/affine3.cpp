#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void affine_rotation() {
	Mat src = imread("tekapo.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Point2f cp(src.cols / 2.f, src.rows / 2.f);
	// ������ �߽� ��ǥ�� ����Ű�� ���� cp
	Mat M = getRotationMatrix2D(cp, 20, 1);
	// cp ��ǥ�� �������� 20�� ȸ��
	Mat dst;
	warpAffine(src, dst, M, Size());
	
	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}
