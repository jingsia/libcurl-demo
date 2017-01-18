/*************************************************************************
	> File Name: get_html.c
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 18 Jan 2017 09:48:02 AM CST
 ************************************************************************/

#include<stdio.h>
#include<curl/curl.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	CURL *curl;
	CURLcode res;
	if(argc != 2)
	{
		printf("Usage : file <url>;\n");
		exit(1);
	}

	curl = curl_easy_init();
	if(curl != NULL)
	{
		curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
		res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}

	return 0;
}
//[jingsia@localhost ~]$ gcc get_html.c -o get_html -lcurl
//[jingsia@localhost ~]$ ./get_html www.baidu.com > 1

