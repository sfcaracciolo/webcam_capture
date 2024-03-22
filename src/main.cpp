#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

int main(int argc, char** argv)
{

    // image 
    // std::string image_path = "C:/Users/Santiago/Desktop/41028670.jpg";
    // cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    // cv::imshow("Display window", img);
    // int k = cv::waitKey(0); // Wait for a keystroke in the window

    // video 
    cv::VideoCapture cap;
    cv::Mat frame;

    int ix = atoi(argv[1]);

    cap.open(ix);
    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    while (true)
    {
        cap.read(frame);
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        cv::imshow("Live", frame);
        if (cv::waitKey(5) >= 0) break;
    }
    
    return 0;
}