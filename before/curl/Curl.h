#ifndef _H_CURL
#define _H_CURL

#include <string>

//include lib curl for C++ wrapper.
#ifdef _cplusplus
extern "C" {
#endif
#include <curl/curl.h>

#ifdef _cplusplus
}
#endif

namespace curl {

size_t WriteMemoryCallback(char* contents, size_t size, size_t nmemb, void *userp);
	
struct MemoryStruct {
  char *memory;
  size_t size;
};

class Curl {
public:
	Curl(){ init(); }
	void get(const std::string& url);
	bool status();
	MemoryStruct data(); 

	~Curl() {
		curl_easy_cleanup(mCurlHandle);
		if(mChunk.memory != NULL) {
			free(mChunk.memory);
		}
		curl_global_cleanup();
	}

private:
	void init(); 

private:
	CURL* mCurlHandle;
	MemoryStruct mChunk;
	CURLcode mStatus;
};

} //namespace curl

#endif
