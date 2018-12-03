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

int main(int argc, const char * argv[]) {
    Mat img;
    img = imread("./Images/1.jpeg");
    blur(img, img, Size(10, 10));

    Mat grayScaleImg(img.rows, img.cols, CV_8UC1);
    cvtColor(img, grayScaleImg, COLOR_BGR2GRAY);
    
    Canny(grayScaleImg, grayScaleImg, 0.1, 0.8);
    
    
    
    imshow("OpenCV Learn", grayScaleImg);
    waitKey();
    return 0;
}
