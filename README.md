# OpenCV CSV Wrapper
This C++ code provides a wrapper to be able to save OpenCV matrix in CSV file
##Motivation
I like the MATLAB functions that visualize matrix element using imagesc and imshow. I didn't find similar easy to use alternative functions in OpenCV library. There is no way to inspect matrix elements like Data cursor tool in MATLAB figures. Also sometimes, you want to implement some MATLAB functions using C++&OpenCV. This wrapper can help you validate your implementation. It help save your C++ result in a format that can be easily read by MATLAB for further validation.
##Setup
This is an Xcode project developing over XOS.
1. Download
2. Make sure to fix the OpenCV library linkage in the project build settings.
3. Run the Xcode project, csv files will be saved in the product Directory.
4. You can validate the csv files using validate_csv.m MATLAB script. 

For help, please contact ahmdtaha [@] cs dot umd dot edu

##Contributor list

1. [Ahmed Taha](http://www.cs.umd.edu/~ahmdtaha/) 

##Contribution guidelines
I hope to extend this to contain more functions similar to those present in MATLAB like meshgrid, () operator with its variants ((:), (2:2:4,:)).
Any contribution to any of these issues is welcomed.

##License
Copyright (c) 2016, Ahmed Taha (ahmdtaha [@] cs dot umd dot edu)
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

- Re distributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
- Re distributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.