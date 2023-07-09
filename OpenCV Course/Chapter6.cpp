#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Color Detection
*/

int main() {

	string path = "Resources/lambo.png";
	Mat img = imread(path);
	Mat imgHSV, mask;
	
	// convert to HSV
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	// Create new window with trackbars
	namedWindow("Trackbars", (640, 200)); // size of window is 640x200 
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Mask", mask);
		waitKey(1);
	}

	return 0;
}