#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
Reading and Displaying Images, Videos and Video Sources
*/

// Display images
void readAndDisplayIMG() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("Test Image", img);
	waitKey(0);
}

// Display videos
void readAndDisplayVID() {
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat frame;

	while (true) {
		cap.read(frame);
		if (frame.empty())
			break;
		imshow("Test Video", frame);
		int fps = cap.get(CAP_PROP_FPS);
		int delay = 1000 / fps; // 30 fps => 30 frames in 1000ms => each frame is displayed for 1000/30 ms
		waitKey(delay);
	}

	// waitKey(0);
}

void readAndDisplayWEBCAM() {
	VideoCapture cap(0);
	Mat frame;

	while (true) {
		cap.read(frame);
		if (frame.empty())
			break;
		imshow("Webcam", frame);
		waitKey(1); // 1ms delay
	}
}

int main() {

	// readAndDisplayIMG();
	// readAndDisplayVID();
	readAndDisplayWEBCAM();
	return 0;
}