/*
Input Format
The first line contains an integer, the number of test cases.
Each of the  subsequent lines describes a test case as a single username string, .


Output Format
You are not responsible for directly printing anything to stdout. If your code is correct, the locked stub code in your 
editor will print either Valid (if the username is valid), Invalid (if the username is invalid), or Too short: 
n (where  is the length of the too-short username) on a new line for each test case.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException : public std::exception {
private:
    int _message;
public:
    BadLengthException(const int& num){
        _message = num;
    }
    int what() {
        return _message;
    }
}; 

class BadLengthException : public std::exception
{
    int _msg;
public:
    BadLengthException(const int& num) : _msg(num){
    }

    virtual const char* what() const noexcept override
    {
        return "324";
    }
}; 


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
