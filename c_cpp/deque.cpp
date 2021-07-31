/*
Given a set of arrays of size N and an integer K, you have to find the maximum integer 
for each and every contiguous subarray of size K for each of the given arrays.

ex input:
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

ex output:
4 6 6 4
8 8 8 10
*/

#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;


void printKMax(int arr[], int n, int k)
{
    std::deque<int> Qi(k);
    int i;
    for (i = 0; i < k; ++i){
        // warm start
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (; i < n; ++i){
        // clean up
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
        // update
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
         Qi.push_back(i);
    }
    cout << arr[Qi.front()] << endl;
    
}
int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
