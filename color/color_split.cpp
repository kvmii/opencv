#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// split(InputArray, OutputArrayOfArrays) 색상 채널 나누기
// murge(InputArrayOfArrays, OutputArray) 색상 채널 합치기

void color_split() {
	Mat src = imread("candies.png");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	imshow("src", src);
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);

	waitKey();
	destroyAllWindows();
}

int main() {
	color_split();
}