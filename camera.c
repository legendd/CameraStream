//#include <stdafx.h>
#include <highgui.h>
#include <cv.h>

int main()
{
    cvNamedWindow( "window", 1);

    IplImage *frame;
    CvCapture *capture;
    capture = cvCaptureFromCAM(0);  
    while(true){
        frame = cvQueryFrame(capture);
        cvShowImage("window", frame);   

        cvWaitKey(30);
    }
    cvReleaseImage(&frame);
    return 0;	
}
