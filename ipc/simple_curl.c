#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  CURL *curl;
  CURLcode res;
  char message[256];

/*fork();
  fork();
  fork();
  fork();
  fork();
  fork();
  fork(); */

//  message ="\{\"id\":1,\"name\":\"hitesh\",\"comments\":\"hitesh\"\}"; 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:10011/order/get");
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    //curl_easy_setopt(curl, CURLOPT_PROXY, "http://genproxy:8080"); 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
      printf("\n"); 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  return 0;
}
