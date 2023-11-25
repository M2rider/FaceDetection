#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// code for opening an image on the pc

/*
void main() {
	string path = "faceImg.png";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}
*/

void main() {
	CascadeClassifier facedetect;
	facedetect.load("haarcascade_frontalface_default.xml");
	
	
	while (true) {
		// index of web cam is 0;
		VideoCapture video(0);

		// To detect the face
		CascadeClassifier facedetect;
		facedetect.load("haarcascade_frontalface_default.xml");

		// img is a matrice
		// image is stored as a matrice
		Mat img;
		while (true) {
			// the video captured from the web cam is stored in img 
			video.read(img);

			// we will create a vector of faces of dataType rectangle (this is a class)
			// we can get the top left and bottom right postion of the face from here
			vector<Rect> faces;
			// detectMultiScale will detect the image and will store the information such as the coordinates (x,y) of the 
			// detected faces
			facedetect.detectMultiScale(img, faces, 1.3, 5);

			cout << faces.size() << endl;

			for (int i = 0; i < faces.size(); i++) {
				rectangle(img, faces[i].tl(), faces[i].br(), Scalar(42, 170, 50), 3);
				rectangle(img, Point(0, 0), Point(250, 70), Scalar(127, 0, 255), FILLED);
				putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 1);
			}

			// this will show the webcam video
			imshow("Frame", img);
			waitKey(1);
		}
	}
}

