#include"opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void setLabel(Mat& img, const vector<Point>& pts, const String& label) {
	Rect rc = boundingRect(pts);
	// 사각형 그리기
	rectangle(img, rc, Scalar(0, 0, 255), 1);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
}

int main(int argc, char* argv[]) {
	Mat img = imread("polygon.bmp", IMREAD_COLOR);

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	// 색상 변화

	Mat bin;
	threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);
	// 이진화

	vector<vector<Point>> contours;
	findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	for (vector<Point>& pts : contours) {
		// 면적 구하기
		// 외곽선이 감싸는 면적이 400보다 작으면 무시
		if (contourArea(pts) < 400)
			continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);
		// 곡선 근사화

		int vtc = (int)approx.size();
		// 외곽선 점의 개수

		if (vtc == 3) {
			setLabel(img, pts, "TRI");
		}
		else if (vtc == 4) {
			setLabel(img, pts, "RECT");
		}
		else if (vtc > 4) {
			double len = arcLength(pts, true);
			double area = contourArea(pts);
			double ratio = 4 * CV_PI * area / (len * len);
			// 면적 대 길이 비율을 조사형 원에 가까우면

			if (ratio > 0.8) {
				setLabel(img, pts, "CIR");
			}
		}
	}

	imshow("img", img);
	waitKey();
	return 0;
}