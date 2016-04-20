#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/stitching.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

vector<Mat> imgs;
String resultImg = "camPano.jpg";

int main()
{
    VideoCapture cap(0);
    VideoCapture cap2(1);
    double t = 0;

    if(!cap.isOpened())
    {
	cout << "Camera #1 is not open." << endl;
	return -1;    
    }
    if(!cap2.isOpened())
    {
        cout << "Camera #1 is not open." << endl;
        return -1;
    }
    //double frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    bool set_frame_width1 = cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
    bool set_frame_height1 = cap.set(CV_CAP_PROP_FRAME_HEIGHT,320);
    double get_frame_width1 = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double get_frame_height1 = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    cout << "#1 Frame width:" << get_frame_width1 << "   Frame height:" << get_frame_height1 << endl;

    bool set_frame_width2 = cap2.set(CV_CAP_PROP_FRAME_WIDTH,320);
    bool set_frame_height2 = cap2.set(CV_CAP_PROP_FRAME_HEIGHT,320);
    double get_frame_width2 = cap2.get(CV_CAP_PROP_FRAME_WIDTH);
    double get_frame_height2 = cap2.get(CV_CAP_PROP_FRAME_WIDTH);
    cout << "#2 Frame width:" << get_frame_width2 << "   Frame height:" << get_frame_height2 << endl;

    double fps1 = 0.0;
    double fps2 = 0.0;
    fps1 = cap.get(CV_CAP_PROP_FPS);
    fps2 = cap2.get(CV_CAP_PROP_FPS);
    cout << "#1 FPS = " << fps1 << "    #2 FPS = " << fps2<< endl;

    //Stitcher stitcher = Stitcher::createDefault();

    while(1){
	Mat frame1, frame2, pano;
	if(!cap.read(frame1))
	{
	    cout << "Cannot Read frames from camera 1." << endl;
	    break;
	}
	if(!cap2.read(frame2))
        {
            cout << "Cannot read frames from camera 2." << endl;
            break;
        }
#if 0
	if(frame1.empty() != 0 && frame2.empty() != 0)
	{
	    imgs.push_back(frame1);
	    imgs.push_back(frame2);
	    imwrite("frame1.jpg", frame1);
	    imwrite("frame2.jpg", frame2);

	    Stitcher::Status status = stitcher.stitch(imgs, pano);
	    if(status != Stitcher::OK)
	    {
	        cout << "Can't stitch imgs. ERROR CODE="<< (int)status << endl;
	    }

	    imshow("Cam1", frame1);
	    imshow("Cam2", frame2);
	    //imwrite(resultImg, pano);

	    if(waitKey(30) == 27)
	    {
	        cout << "ESC FOR ENDING." << endl;	
	    }

	    for(int i = 0; i < imgs.size(); i++)
	    {
	        imgs[i] = cv::Mat();
	    }
	}
#endif
#if 1
	imshow("VIDEO", frame1);
	if(waitKey(30) == 27)
        {
            cout << "ESC FOR ENDING." << endl;
            break;
        }

	imshow("VIDEO2", frame2);
	if(waitKey(30) == 27)
	{
	    cout << "ESC FOR ENDING." << endl;
	    break;
	}
#endif
  //  }
}
    return 0;
}

