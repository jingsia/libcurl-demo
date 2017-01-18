/*************************************************************************
	> File Name: get_post.c
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 18 Jan 2017 03:30:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<curl/curl.h>

int getUrl(char * filename)
{
	CURL *curl;
	CURLcode res;
	FILE *fp;
	if((fp = fopen(filename, "w")) == NULL)
	{
		return 1;
	}

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Accept: Agent-007");
	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp);
		res = curl_easy_perform(curl);
		if(res != 0)
		{
			curl_slist_free_all(headers);
			curl_easy_cleanup(curl);
		}
		fclose(fp);
		return 0;
	}
}

int postUrl(char *filename)
{
	CURL *curl;
	CURLcode res;
	FILE *fp;
	if((fp = fopen(filename, "w")) == NULL)
	{
		return 1;
	}
	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "&logintype=uid&u=xieyan&psw=xxx86");
		curl_easy_setopt(curl, CURLOPT_URL, "http://mail.sina.com.cn/cgi-bin/login.cgi");
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	fclose(fp);
	return 0;
}
int main()
{
	getUrl("/tmp/get.html");
	postUrl("/tmp/post.html");
	return 0;
}

