#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void affine_flip() {
	Mat src = imread("eastsea.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	imshow("src", src);

	Mat dst;
	int flipCode[] = { 1, 0 ,-1 };
	for (int i = 0; i < 3; i++) {
		flip(src, dst, flipCode[i]);

		String desc = format("flipCode: %d", flipCode[i]);
		// flipcode = 1 ÁÂ¿ì´ëÄª
		// flipcode = 0 »óÇÏ´ëÄª
		// flipcode = -1 µÑ´Ù
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);
		
		imshow("dst", dst);
		waitKey();
	}


	destroyAllWindows();
}

int main() {
	affine_flip();
}