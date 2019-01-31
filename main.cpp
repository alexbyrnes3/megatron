//
//  main.cpp
//  gripFileTrial
//
//  Created by Alex Byrnes on 1/17/19.
//  Copyright © 2019 Alex Byrnes. All rights reserved.
//


#pragma once
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#include "FootballPipeline.h"

using namespace std;
using namespace cv;
using namespace grip;

int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;
//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

int main(int argc, char* argv[])
{

    //Matrix to store each frame of the webcam feed
    Mat cameraFeed;
    //matrix storage for HSV image
    Mat HSV;
    //matrix storage for binary threshold image
    Mat threshold;
    //x and y values for the location of the object
    //int x=0, y=0;
    //video capture object to acquire webcam feed
    VideoCapture capture(0);
    //set height and width of capture frame
    capture.set(CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    capture.set(CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
    capture.set(CAP_PROP_FPS, 60);
    //start an infinite loop where webcam feed is copied to cameraFeed matrix
    
    FootballPipeline pipe;
    // imshow("Sneak Peak", *pipe.GetHslThresholdOutput());

    int i = 1;
    while(i < 100){
        //store image to matrix

        // Attempting to find blobs
        capture.read(cameraFeed);
    
        pipe.Process(cameraFeed);

        vector<KeyPoint> points = *pipe.GetFindBlobsOutput();

        

        //checking the existence of blobs
        int i =0 ;
        if (i < points.size()) {
            int x1 = points[0].pt.x;
            int y1 = points[0].pt.y;
            cout << "X: " << x1 << ", Y:" << y1 << ")\n";

        }

        


        //image will not appear without this waitKey() command
        waitKey(17);
        i++;
    }

    cout << "bitch\n";
    
    return 0;
}
