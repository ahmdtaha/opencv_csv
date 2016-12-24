//
//  main.cpp
//  opencv_csv
//
//  Created by Ahmed Taha on 12/23/16.
//  Copyright (c) 2016 Ahmed Taha. All rights reserved.
//

#include <iostream>
#include "opencv2/opencv.hpp"
#include "Utils.h"
#include <stdlib.h>     /* srand, rand */

using namespace std;
using namespace cv;

Mat create_int_2d2c_mat();
Mat create_double_2d1c_mat();

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, OpenCV!\n";
    char cwd[256];
    getcwd(cwd, 255);
    
    Mat int_mat = create_int_2d2c_mat();
    cout << int_mat << endl;
    writeMat<int>(string(cwd)+"/int_mat.csv", int_mat,1,true,true);

    
    Mat double_mat = create_double_2d1c_mat();
    cout << double_mat << endl;
    writeMat<double>(string(cwd)+"/double_mat.csv", double_mat,64,true);

    
    Mat img = cv::imread("sm_img.png");
    writeMat<unsigned char>(string(cwd)+"/brg_img.csv", img,1);
    cv::cvtColor(img, img, CV_BGR2RGB);
    writeMat<unsigned char>(string(cwd)+"/rgb_img.csv", img,1);
    cv::cvtColor(img, img, CV_RGB2GRAY);
    writeMat<unsigned char>(string(cwd)+"/gray_img.csv", img,1);
    
    img = im2single(img);
    writeMat<float>(string(cwd)+"/single_img.csv", img,32);
    
    
    //writeMat<int>(string(cwd)+"/int_mat.csv", tmp,1,true);
    Mat read_int_tmp = readMat<int>(string(cwd)+"/int_mat.csv");
    cout << read_int_tmp << endl;

    Mat read_double_tmp = readMat<double>(string(cwd)+"/double_mat.csv");
    cout << read_double_tmp << endl;

    return 0;
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

Mat create_double_2d1c_mat()
{
    std::srand((unsigned int)std::time(0));
    
    Mat double_mat = Mat::zeros(5, 5, CV_64F);
    int cols = 5;
    double* ptr = double_mat.ptr<double>(0);
    for (int row = 0;row< 5;row++)
        for (int col = 0;col< 5;col++)
            ptr[row*cols+col] = fRand(0,1);
    
    return double_mat;
}
Mat create_int_2d2c_mat()
{
    Mat int_mat;
    Mat channels[2];
    channels[0] = Mat::zeros(5, 5, CV_32S);
    channels[0].at<int>(0,0)=10;
    channels[0].at<int>(1,1)=2;
    channels[1] = Mat::zeros(5, 5, CV_32S);
    channels[1].at<int>(0,0)=4;
    channels[1].at<int>(4,4)=3;
    cv::merge(channels, 2, int_mat);
    return int_mat;
}
