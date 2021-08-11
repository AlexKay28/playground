/*
Input
The first line contains an integer, the number of test cases.
Each of the  subsequent lines describes a test case as  space-separated integers

Output 
For each test case, print a single line containing whichever message described in the Problem Statement above is appropriate. 
After all messages have been printed, the locked stub code in your editor prints the server load.
*/

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) 
      throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};

int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
        try {
            cout << Server::compute(A,B) << endl;
        } catch (const std::bad_alloc& msg) {
            cout << "Not enough memory" << endl;
        } catch (const std::exception& msg) {
            cout << "Exception: " << msg.what() << endl;
        } catch (...) {
            cout << "Other Exception" << endl;
        }
	}
	cout << Server::getLoad() << endl;
	return 0;
}
