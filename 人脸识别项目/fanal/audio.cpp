#include "aip-cpp-sdk/speech.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include <stdlib.h>

using namespace Json;
using namespace std;
using namespace aip;

int main(void)
{
	string app_id="20351610";
	string api_key="4tAHwH3Gi0PzWI3Z0YizuSQN";
	string secret_key="OOzV3HrEdZsoQTjkKccVN21XFBrP0kP1";
	
	ofstream ofile;
	string file_ret;
	Speech client(app_id,api_key,secret_key);
	
	ofile.open("test.mp3",ios::out|ios::binary);	
	Value result=client.text2audio("hello world!!!",aip::null,file_ret);
	
	if(!file_ret.empty())
	{
		ofile<<file_ret;
	}
	else
	{
		cout<<result.toStyledString();
	}
	return 0;
}
