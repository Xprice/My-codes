/**************************************************
* File Name: face_car_audio.cpp
* Author: x.price
* Mail: x.price@gmail.com
* Created Time: 2020-06-12/09:04:46
**************************************************/
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include "aip-cpp-sdk/face.h"
#include <jsoncpp/json/json.h>

#include "aip-cpp-sdk/ocr.h"
#include <string>

#include "aip-cpp-sdk/speech.h"

#include <stdlib.h>

using namespace std;
using namespace cv;
using namespace aip;
using namespace Json;

Mat image;
Rect face;//框区域
pthread_mutex_t myMutex;

void * audio(void * arg)
{
	string app_id="20351610";
	string api_key="4tAHwH3Gi0PzWI3Z0YizuSQN";
	string secret_key="OOzV3HrEdZsoQTjkKccVN21XFBrP0kP1";
	
	ofstream ofile;
	string file_ret;
	Speech client(app_id,api_key,secret_key);
	while(1)
	{
		ofile.open("a.mp3",ios::out|ios::binary);	
		Value result=client.text2audio("惊雷，这通天修为天塌地陷紫金锤，紫电，说玄真火焰九天悬剑惊天变。乌云，我驰骋沙场呼啸烟雨顿。多情自古空余恨我手持乐弯月刃。",aip::null,file_ret);
	
		system("play a.mp3");
		cout<<"succcess"<<endl;
		if(!file_ret.empty())
		{
			ofile<<file_ret;
		}
		else
		{
			cout<<result.toStyledString();
		}
	}
}
void * chepai(void * arg)
{
	string app_id="20353085";
	string api_key="XEiK5SLrg7ltCpiTZRUKEsIN";
	string secret_key="e6PwLSN6q7tbXeZXAPs0DTkkKPsLG03I";
	
	Ocr client(app_id,api_key,secret_key);
	while(1)
	{
		string img;
		get_file_content("123.jpg",&img);
		cout<<"result="<<endl;
		map <string,string> options;
		options["multi_detect"]="true";
	
		Value result=client.license_plate(img,options);

		if(result["words_result"].isArray())
		{
			for(unsigned int i=0;i<result["words_result"].size();i++)
			{
				cout<<result["words_result"][i]["number"]<<endl;
			}
		}	
	}
}

void * face_result(void * arg)//人脸检测子线程
{
	Mat gray;
	CascadeClassifier classifier;
	classifier.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml");
	
	string app_id="20350614";
	string api_key="6y6NUz2OWp1LemNDMOnkyyvp";
	string secret_key="P7bA4k7BIVC5YTeHg959w4EXNGB2k6MX";
	
	aip::Face client(app_id,api_key,secret_key);
	
	while(1)
	{
		pthread_mutex_lock(&myMutex);
		cvtColor(image,gray,COLOR_BGR2GRAY);//变成灰色
		pthread_mutex_unlock(&myMutex);
		
		
		equalizeHist(gray,gray);//图像均衡化
		vector <Rect>faces;   //
		classifier.detectMultiScale(gray,faces);//检测人脸
		if(faces.size())
		{
			pthread_mutex_lock(&myMutex);
			face=faces[0];
			pthread_mutex_unlock(&myMutex);
			
			Mat faceRect(image,faces[0]);
			vector <unsigned char>buf;
			imencode(".jpg",faceRect,buf);
			string faceimg=base64_encode((char *)buf.data(),buf.size());
			
			Value per_json=client.search(faceimg,"BASE64","G1",aip::null);
			float score=per_json["result"]["user_list"][0]["score"].asFloat();
			
			string per_name=per_json["result"]["user_list"][0]["user_id"].asString();
			if(score>=90)
			{
				cout<<per_name<<"打卡成功"<<endl;
			}
		}
		usleep(20000);
	}
}

int main(void)
{
	VideoCapture cam(0);
	namedWindow("cam");

	cam>>image;
	pthread_t pid1;
	pthread_t pid2;
	pthread_t pid3;

	pthread_mutex_init(&myMutex,nullptr);
	
	pthread_create(&pid1,nullptr,face_result,nullptr);
	pthread_create(&pid2,nullptr,chepai,nullptr);
	pthread_create(&pid3,nullptr,audio,nullptr);
	
	while(1)
	{
		pthread_mutex_lock(&myMutex);
		cam>>image;
		pthread_mutex_unlock(&myMutex);
		pthread_mutex_lock(&myMutex);
		rectangle(image,face,CV_RGB(255,0,0));//
		pthread_mutex_unlock(&myMutex);

		imshow("cam",image);
		if(waitKey(40)!=255) break;
	}
	pthread_mutex_destroy(&myMutex);

	return 0;
}
