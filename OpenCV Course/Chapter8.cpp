#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

/*
Face Detection
*/

void usingIMG() {
	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty())
		cout << "XML not loaded" << endl;

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i], Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(0);
}

void usingWEBCAM() {
	VideoCapture cap(0);
	Mat frame;

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty())
		cout << "XML not loaded" << endl;

	vector<Rect> faces;

	while (true) {
		cap.read(frame);
		if (frame.empty())
			break;

		faceCascade.detectMultiScale(frame, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(frame, faces[i], Scalar(255, 0, 255), 3);
		}

		imshow("Webcam", frame);
		waitKey(1);
	}
}

int main() {

	// usingIMG();
	usingWEBCAM();

	return 0;
}