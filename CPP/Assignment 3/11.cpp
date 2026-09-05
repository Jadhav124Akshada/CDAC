#include<iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

enum class HttpStatus {
 OK = 200,
 Created = 201,
 BadRequest = 400,
 Unauthorized = 401,
 NotFound = 404,
 ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint){

switch (static_cast<int>(status)) {
    case 200:
    	cout << "[" << endpoint << "] → 200 OK : Request successful" << endl;
    	break;
    case 401:
    	cout << "[" << endpoint << "] → 401 Unauthorized : Authentication required" << endl;
    	break;
    case 404:
    	cout << "[" << endpoint << "] → 404 Not found : Endpoint does not exist" << endl;
    	break;
    case 500:
    	cout << "[" << endpoint << "] → 500 Server Error : Internal server error -retry later" << endl;
    	break;
    default:
    	break;
}
}
using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;
void printHeaders(const HeaderList& headers) {
    cout << "Headers:" << endl;
    for (const auto& h : headers) {
        cout << " " << h.first << " : " << h.second << endl;
    }
}

 int main11(){
	 handleResponse(HttpStatus::OK, "GET /api/users");
	 handleResponse(HttpStatus::Unauthorized, "POST /api/login");
	 handleResponse(HttpStatus::NotFound, "GET /api/products/99");
	 handleResponse(HttpStatus::ServerError, "GET /api/order");
    cout<<endl;

	 RequestId reqId = 1748293847;
	 Port serverPort = 8080;

	     HeaderList headers = {
	         {"Content-Type", "application/json"},
	         {"Authorization", "Bearer eyJhbGci..."},
	         {"Accept-Language", "en"}
	     };

	     cout << "Request ID : " << reqId << endl;
	     cout << "Server Port : " << serverPort << endl;
	     printHeaders(headers);
return 0;

 }
