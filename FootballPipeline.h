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

namespace grip {

/**
* A representation of the different types of blurs that can be used.
*
*/
enum BlurType {
	BOX, GAUSSIAN, MEDIAN, BILATERAL
};
/**
* FootballPipeline class.
* 
* An OpenCV pipeline generated by GRIP.
*/
class FootballPipeline {
	private:
		cv::Mat blurOutput;
		cv::Mat hslThresholdOutput;
		std::vector<cv::KeyPoint> findBlobsOutput;
		void blur(cv::Mat &, BlurType &, double , cv::Mat &);
		void hslThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
		void findBlobs(cv::Mat &, double , double [], bool , std::vector<cv::KeyPoint> &);

	public:
		FootballPipeline();
		void Process(cv::Mat& source0);
		cv::Mat* GetBlurOutput();
		cv::Mat* GetHslThresholdOutput();
		std::vector<cv::KeyPoint>* GetFindBlobsOutput();
};


} // end namespace grip


