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
	// 영상의 중심 좌표를 가리키는 변수 cp
	Mat M = getRotationMatrix2D(cp, 20, 1);
	// cp 좌표를 기준으로 20도 회전
	Mat dst;
	warpAffine(src, dst, M, Size());
	
	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}
