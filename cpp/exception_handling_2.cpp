/*
The input is read by the provided locked code template. 
In the only line of the input, there is a single integer , 
which is going to be the argument passed to function process_input.
*/

#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl; 
    }
    std::cout << "returning control flow to caller";
}


int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
