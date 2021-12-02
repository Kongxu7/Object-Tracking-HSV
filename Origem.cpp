#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char** argv)		{

	VideoCapture cap(0);

	if (!cap.isOpened())	{

		cout << "Failed to open Camera. " << "\n";
		return -1;

	}

	namedWindow("Control", CV_WINDOW_AUTOSIZE);


	int iLowH = 0;
	int iHighH = 179;
	int iLowS = 0;
	int iHighS = 255;
	int iLowV = 0;
	int iHighV = 255;

	createTrackbar("LowH", "Control", &iLowH, 179);
	   createTrackbar("HighH", "Control", &iHighH, 179);
		 createTrackbar("LowS", "Control", &iLowS, 255);
	createTrackbar("HighS", "Control", &iHighS, 255);
		createTrackbar("LowV", "Control", &iLowV, 255);
		  createTrackbar("HighV", "Control", &iHighV, 255);

	Mat imgtt;
	cap.read(imgtt);


	while (true) {

		Mat frame;

		bool fs = cap.read(frame);

		if (!fs) 
		{
			cout << "Could not read pixel data. " << endl;
			break;
		} 


		Mat HSV;

		cvtColor(frame, HSV, COLOR_BGR2HSV);
		
		Mat TH;


		inRange(HSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), TH);

			Mat r;
			bitwise_and(frame, frame, r, TH);
		
			imshow("frame", frame);
			imshow("Thresholded Image", TH);
			imshow("target", r);

			 


			if (waitKey(30) == 27)	 {
			
			
				break;
			}
	}

	return 0;
}