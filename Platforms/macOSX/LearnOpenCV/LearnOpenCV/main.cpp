//
//  main.cpp
//  LearnOpenCV
//
//  Created by ocean on 2018/12/3.
//  Copyright © 2018 handytool. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void processFrame(Mat &img, Mat &result) {
    Mat grayScaleImg(img.rows, img.cols, CV_8UC1);
//    cvtColor(img, grayScaleImg, COLOR_BGR2GRAY);
    
//    Canny(grayScaleImg, grayScaleImg, 0.7, 0.8);
//    GaussianBlur(img, img, Size(21, 21), 1);
    
    Mat smallerImg(img.rows / 2, img.cols / 2, CV_8UC3);
    pyrDown(img, smallerImg);
    result = smallerImg;
}

void playVideo(const char *videoFilename) {
    namedWindow(videoFilename);
    VideoCapture videoCapture(videoFilename);
//    VideoCapture videoCapture(0);
    Mat image;
    
    int frames = videoCapture.get(CAP_PROP_FRAME_COUNT);
    double width = videoCapture.get(CAP_PROP_FRAME_WIDTH);
    double height = videoCapture.get(CAP_PROP_FRAME_HEIGHT);
    std::cout << "Total Frame: " << frames << std::endl;
    
    int fps = videoCapture.get(CAP_PROP_FPS);
    
    VideoWriter videoWriter("./Output/output.mp4", VideoWriter::fourcc('M','J','P','G'), 30, Size(width, height));
    while (1) {
        videoCapture.read(image);
        videoWriter.write(image);
        processFrame(image, image);
        imshow(videoFilename, image);
        waitKey(1000 / fps);
    }
}

int main(int argc, const char * argv[]) {
//    Mat img;
//    img = imread("./Images/2.jpg");
//    blur(img, img, Size(10, 10));
//
//    Mat grayScaleImg(img.rows, img.cols, CV_8UC1);
//    cvtColor(img, grayScaleImg, COLOR_BGR2GRAY);
//
//    Canny(grayScaleImg, grayScaleImg, 0.7, 0.8);
//
//
//
//    imshow("OpenCV Learn", grayScaleImg);
//    waitKey();

    playVideo("./Images/1.mp4");
    return 0;
}
