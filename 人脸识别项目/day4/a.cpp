/*************************************************************************
    > File Name: a.cpp
    > Author: X.price
    > Mail: 1450362882@qq.com 
    > Created Time: 2020年06月05日 星期五 08时57分22秒
 ************************************************************************/

#include<iostream>
#include<opencv2/opencv.cpp>
using namespace std;
using namespace cv;
int main(){
	VideoCapture cam;
	cam.open(0);
	Mat frame;
		while(1)
		{
			cam>>frame
				imshow("video",frame);
			if(waitKey(10)!=255)
			{
				break;
			}
		}
}
