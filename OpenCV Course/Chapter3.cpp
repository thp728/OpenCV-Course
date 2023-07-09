#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Resize and Crop Images
*/

int main() {

	string path = "Resources/test.png";
	Mat img = imread(path);

	Mat imgResized, imgCropped;

	// Resizing an image
	// cout << img.size() << endl; // 768x559
	resize(img, imgResized, Size(500, 500)); // Scales the image to 500x500, image may get stretched
	resize(img, imgResized, Size(), 0.5, 0.5); // Scales the image by half along X and Y directions, aspect ratio is maintained

	// Cropping an image
	Rect roi(0, 0, 300, 300); // x,y,width,height
	imgCropped = img(roi);

	imshow("Original Image", img);
	imshow("Image Resized", imgResized);
	imshow("Image Cropped", imgCropped);

	waitKey(0);
	return 0;
}