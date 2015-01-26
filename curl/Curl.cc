#include <string.h>
#include <stdlib.h>

#include <string>
#include <functional>

#include "Curl.h"

namespace curl {

size_t WriteMemoryCallback(char* contents,
		size_t size, size_t nmemb, void *userp) {

	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;
	printf("%lu\n", nmemb);

	mem->memory = reinterpret_cast<char*>(realloc(mem->memory, mem->size + realsize + 1));
	if(mem->memory == NULL) {
	printf("not enough memory (realloc returned NULL)\n");
	return 0;
	}
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	return  realsize;
}

void Curl::init() {
	curl_global_init(CURL_GLOBAL_ALL);
	mCurlHandle = curl_easy_init();
	mChunk.memory = reinterpret_cast<char*>(malloc(1));
	mChunk.size = 0;
}


void Curl::get(const std::string& url) {
	//specify url to get
	curl_easy_setopt(mCurlHandle, CURLOPT_URL, url.c_str());
	//register callback function to handle data
	curl_easy_setopt(mCurlHandle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
	//pass chunk to get data
	curl_easy_setopt(mCurlHandle, CURLOPT_WRITEDATA, (void *)&mChunk);
	//set User-Agent
	curl_easy_setopt(mCurlHandle, CURLOPT_USERAGENT, "curl-agent/1.0");
	//do the work
	mStatus = curl_easy_perform(mCurlHandle);
}

bool Curl::status() {
	return mStatus == CURLE_OK;
}

MemoryStruct Curl::data(){
	return mChunk;
}


}//namespace curl
