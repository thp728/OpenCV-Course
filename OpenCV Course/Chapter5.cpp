#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Warping Images
*/

int main() {

	Mat img = imread("Resources/cards.jpg");

	Mat transfMatrix, imgWarp;
	float w = 250, h = 350;

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} }; // source points in order: top left, top right, bot left, bot right
	Point2f dst[4] = { {0.0f, 0.0f},{w, 0.0f}, {0.0f, h}, {w,h} }; // destination points in same order

	transfMatrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, transfMatrix, Size(w, h));

	// Highlight the points in the original image
	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warped", imgWarp);

	waitKey(0);

	return 0;
}