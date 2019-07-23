#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(void)
{
  
  fork();
  fork();
  fork();
  fork();
  fork();
  fork();
  fork(); 
 
  while(1) {

  CURL *curl;
  CURLcode res;
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "charsets: utf-8"); 
  char* jsonObj = "{ \"id\" :1, \"name\" : \"abc\", \"comments\" : \"abc\" }";
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */ 
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
     curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:10011/order/create");
    /* Now specify the POST data */ 
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS,jsonObj);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);  
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
   }
  
  curl_global_cleanup();

 }

  return 0;


}
