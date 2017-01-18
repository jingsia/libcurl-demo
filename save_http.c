/*************************************************************************
	> File Name: save_http.c
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 18 Jan 2017 04:09:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<curl/curl.h>
#include<curl/types.h>
#include<curl/easy.h>

FILE *fp;

size_t write_data(void*ptr, size_t size, size_t nmemb, void *stream)
{
	int written = fwrite(ptr, size, nmemb, (FILE*)fp);
	return written;
}

int main(int argc, char *argv[])
{
	CURL *curl;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

	if((fp = fopen(argv[2], "w")) == NULL)
	{
		curl_easy_cleanup(curl);
		exit(1);
	}

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	exit(0);
}
