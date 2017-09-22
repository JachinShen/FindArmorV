#include "FindArmorV.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

#include <iostream>
#include <vector>
using namespace std;
bool base_color;

int main(void)
{
    cv::VideoCapture cap("/home/jachinshen/Projects/Cpp/Opencv/FindArmorV/real_light.avi"); 
    cv::VideoWriter g_writer;
    string file_name= "/home/jachinshen/视频/FindArmor.avi";
    cv::Mat frame; 
    cv::namedWindow("frame", 1); 
    g_writer.open(file_name, CV_FOURCC('P', 'I', 'M', '1'), 30,
            cv::Size(640, 480));
    cap.read(frame);	
        imshow("frame", frame);
        waitKey(0);
    
    bool BaseFound;
    Point BaseCenter;
    base_color = 0;

    while(cap.read(frame))	
    {
        FindBase(frame, BaseFound, BaseCenter);
        imshow("frame", frame);
        waitKey(0);
        g_writer.write(frame);
    }
    g_writer.release();
}
