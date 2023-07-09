#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Draw Shapes and Text
*/

int main() {

	// Create blank image
	Scalar color(255, 255, 255); // BGR values
	Mat img(512, 512, CV_8UC3, color); // 8UC3 => 8 bit, unsigned, 3 channels

	// Shapes
	Point circleCenter(img.size().width / 2, img.size().height / 2);
	Scalar circleColor(0, 0, 0);
	int radius = 155;
	circle(img, circleCenter, radius, circleColor, FILLED);

	Point topLeft(130, 226);
	Point botRight(382, 286);
	Scalar colorRect(255, 255, 255);
	rectangle(img, topLeft, botRight, colorRect, FILLED);

	Point start(130, 296);
	Point end(382, 296);
	Scalar colorLine(255,255,255);
	int thickness = 2;
	line(img, start, end, colorLine, thickness);

	// Text
	string text = "TEST";
	Point origin(137, 262);
	double fontScale = 0.75;
	Scalar colorText(0, 0, 0);
	putText(img, text, origin, FONT_HERSHEY_DUPLEX, fontScale, colorText, thickness);

	imshow("Image", img);

	waitKey(0);

	return 0;
}