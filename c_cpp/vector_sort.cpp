#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, number;
    vector <int> numbers;
    cout << "Input n:"; cin >> n;
    for (int i=0; i < n; i++){
        cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());

    for (auto number: numbers) {
        cout << number << " ";
    }
    return 0;
}
