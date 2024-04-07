#pragma once

#include "opencv/cv.h"
#include "opencv/cvaux.h"
#include<opencv2\core\core.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\highgui\highgui.hpp> 
using namespace cv;
using namespace std;

static Point cur_pt = (-1, -1);
static Point prev_pt = (-1, -1);

//1.回调函数签名
void onMouse(int event, int x, int y, int flags, void* param);
//2.定义回调函数
void onMouse(int event, int x, int y, int flags, void* param)
{
	cv::Mat* im = reinterpret_cast<cv::Mat*>(param);
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		prev_pt = cur_pt;
		cur_pt = Point(x, y);
		//cv::circle(*im, cur_pt, 3, 2, 1);
		//cout << x << y;
		break;
	}
}