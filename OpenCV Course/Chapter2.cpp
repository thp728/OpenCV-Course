#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Basic Functions of OpenCV: filters, morphological processing, etc.
*/

int main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Converting color profiles
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	// Adding filters
	GaussianBlur(imgGray, imgBlur, Size(5, 5), 5, 0);

	// Edge detection
	Canny(imgBlur, imgCanny, 25, 75);

	// Morphological operations
	Mat se = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, se);
	erode(imgDil, imgErode, se);

	imshow("Origial Image", img);
	imshow("Grayscale Image", imgGray);
	imshow("Blurred Image", imgBlur);
	imshow("Canny Detected Image", imgCanny);
	imshow("Dilated Image", imgDil);
	imshow("Eroded Image", imgErode);


	waitKey(0);

	return 0;
}