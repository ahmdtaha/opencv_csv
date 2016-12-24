//
//  Utils.h
//  opencv_csv
//
//  Created by Ahmed Taha on 12/23/16.
//  Copyright (c) 2016 Ahmed Taha. All rights reserved.
//

#ifndef opencv_csv_Utils_h
#define opencv_csv_Utils_h

#include <iomanip>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

Mat im2single(Mat img)
{
    img.convertTo(img, CV_32F);
    img = img / 255.0;
    return img;
}





template <typename T>
Mat readMat(string filename)
{
    std::ifstream myfile;
    string str;
    myfile.open(filename);
    int rows,cols,channels,type;
    int cols_channels;
    getline(myfile, str);
    std::stringstream ss(str);
    char splice;
    ss >> rows >>splice>>cols>> splice >> channels >> splice >> type;
    cols_channels = cols * channels;
    
    Mat loadedMat = Mat(rows, cols, type);
    T* ptr = loadedMat.ptr<T>(0);
    T read_value;
    for(int row=0;row<rows;row++)
    {
        getline(myfile, str);
        std::stringstream ss(str);
        int col;
        for (col=0; col<cols_channels-1; col++) {
            ss >> read_value >>splice;
            //loadedMat.at<complex<double>>(i,j) = complex<double>(real_v,imag_v);
            ptr[row*cols_channels+col] =read_value;
        }
        ss >> read_value;
        ptr[row*cols_channels+col] =read_value;
    }
    
    return loadedMat;
}




/**
 This function saves a mat into a csv file
 
 filename : The path of where to save the mat
 
 m: is the mat to be saved
 
 precision: is the percision needed when saving float or double values.
 ***If you are saving an int mat, you can use 1 for this param
 
 save_header: By default this value is false. I set it to true if I plan to load the csv file
 ***again using readMat function. readMat assumes the first line in csv file to contain mat
 ***information <num_rows,num_cols,num_channels>
 
 verbose: just a bool to enable log when debugging.
 **/
template <typename T>
void writeMat(string filename, cv::Mat m,int precision,bool save_header=false,bool verbose=false)
{
    std::ofstream myfile;
    std::stringstream ss;
    //cout << "wirting mat to csv file" << endl;
    myfile.open(filename);
    
    if(save_header)
    {
        ss << m.rows << "," << m.cols << "," << m.channels() << "," << m.type() << endl;
    }
    
    T* ptr = m.ptr<T>(0);
    
    int cols_channels = m.cols * m.channels();
    for (int row=0;row<m.rows; row++)
    {
        for (int col=0;col<cols_channels; col++)
        {
            
            if(col == cols_channels-1)
                ss << setprecision(precision) << +ptr[row*cols_channels+col];
            else
                ss << setprecision(precision) << +ptr[row*cols_channels+col] << ",";
        }
        ss << endl;
        
        if(row % 300 == 0)
        {
            myfile << ss.str();
            myfile.flush();
            ss.str(std::string());
        }
        
    }
    myfile << ss.str();
    myfile.close();
    
    if(verbose)
        cout << "csv file saved at " << filename << endl;
}


#endif
