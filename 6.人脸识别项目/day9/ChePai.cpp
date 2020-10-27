#include "aip-cpp-sdk/ocr.h"
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>

using namespace std;
using namespace aip;
using namespace Json;

void chepai(void)
{
	string app_id="20353085";
	string api_key="XEiK5SLrg7ltCpiTZRUKEsIN";
	string secret_key="e6PwLSN6q7tbXeZXAPs0DTkkKPsLG03I";
	
	Ocr client(app_id,api_key,secret_key);
	
	string image;
	get_file_content("car.jpg",&image);
	cout<<"result="<<endl;
	map <string,string> options;
	options["multi_detect"]="true";
	
	Value result=client.license_plate(image,options);

	if(result["words_result"].isArray())
	{
		for(unsigned int i=0;i<result["words_result"].size();i++)
		{
			cout<<result["words_result"][i]["number"]<<endl;
		}
	}
}
int main(void)
{
	chepai();
}
