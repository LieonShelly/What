//
//  main.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/2.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <iostream>
#include "SmartPointer.hpp"
#include <math.h>
#include <opencv2/opencv.hpp>

int main( int argc, char** argv ) {

  cv::Mat img = cv::imread("/Users/lieon/Desktop/lieon/Demo/C++Demo/C++Demo/box.png", -1 );

  if( img.empty() ) return -1;

  cv::namedWindow( "Example 2-1", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Example 2-1", img );
  cv::waitKey( 0 );
  cv::destroyWindow( "Example 2-1" );

  return 0;
}
