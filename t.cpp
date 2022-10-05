#include <iostream>
#include <string>
#include <curl/curl.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include<sstream>
#include<fstream>
#include<algorithm>

using namespace std;


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    ofstream o;
    o.open("dump.txt");
    o << readBuffer;
    o.close();

    fstream file;
    file.open("dump.txt", ios::in);
    string tp;
	int u = 1;    
      while(getline(file, tp)){
	      string s("<body>");

	      string s1("</body>");
	      if(tp.find(s) != string::npos){
		      u--;
	      cout << "start" << u << endl;}
	      if(tp.find(s1) != string::npos){
		      u++;
	      cout << "end" << u << endl;}

		if(u == 0){		      
	     char bl[] = "<>/";
	     for (unsigned int i = 0; i < strlen(bl); ++i){
  
      tp.erase (std::remove(tp.begin(), tp.end(), bl[i]), tp.end());
   }
	    cout << tp << "\n"; 
      }}
    file.close();

  }
  return 0;
}

