#include"opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
Point2f srcQuad[4], dstQuad[4];

void on_mouse(int event, int x, int y, int flags, void* userdata);

int main() {
	src = imread("card.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return - 1;
	}

	namedWindow("src");
	setMouseCallback("src", on_mouse);

	imshow("src", src);
	waitKey();
	destroyAllWindows();
}

void on_mouse(int event, int x, int y, int flags, void* ) {
	static int cnt = 0;
	// 마우스 왼쪽버튼이 눌린 횟수

	if (event == EVENT_LBUTTONDOWN) {
		if (cnt < 4) {
			srcQuad[cnt++] = Point2f(x, y);
			// 마우스 좌표 저장

			circle(src, Point(x, y), 5, Scalar(0, 0, 255), -1);
			// 마우스 누른 곳에 빨간색 원을 그림
			imshow("src", src);

			if (cnt == 4) {
				int w = 200, h = 300;

				dstQuad[0] = Point2f(0, 0);
				dstQuad[1] = Point2f(w - 1, 0);
				dstQuad[2] = Point2f(w - 1, h - 1);
				dstQuad[3] = Point2f(0, h - 1);
				// 이동할 결과 영상 좌표

				Mat pers = getPerspectiveTransform(srcQuad, dstQuad);
				// 3 x 3 투시 변환 행렬 저장

				Mat dst;
				warpPerspective(src, dst, pers, Size(w, h));

				imshow("dst",dst);
			}
		}
	}
}