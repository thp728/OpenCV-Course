#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Contour Detection
*/

void getContours(Mat imgDil, Mat img) {
	
	// Array of contours
	// Every contour is an array of the corner points of that contour
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	// drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size()); // stores approximated polygon shape of contours
	vector<Rect> boundingBox(contours.size()); // stores bounding boxes of the approx poly shapes

	// Traverse all contours
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		string shapeType = "";

		// Filter out small contours
		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			boundingBox[i] = boundingRect(conPoly[i]);

			int shapeCorners = (int)conPoly[i].size();
			if (shapeCorners == 3) shapeType = "Tri";
			if (shapeCorners == 4) {
				double aspRatio = (double)boundingBox[i].width / (double)boundingBox[i].height;
				if (aspRatio >= 0.95 && aspRatio <= 1.05) 
					shapeType = "Square";
				else 
					shapeType = "Rect";
			}
			else if (shapeCorners > 4)
				shapeType = "Circle";

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, { boundingBox[i].tl(), boundingBox[i].br() }, Scalar(0, 255, 0), 5);
			putText(img, shapeType, { boundingBox[i].x, boundingBox[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
		}
	}

}

int main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil;

	// Preprocessing edges
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat se = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, se);

	getContours(imgDil, img);

	imshow("Image", img);
	waitKey(0);

	return 0;
}