/*
You are given a main function which reads the enumeration values for two different types as input, 
then prints out the corresponding enumeration names. 
Write a class template that can provide the names of the enumeration values for both types. 
If the enumeration value is not valid, then print unknown.
*/

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template <typename T> 
struct Traits {
private:
    private:
    static const int max_len;
    static const string names[];
        
public:
    static string name(int & index) {
        if ((index >= max_len) || (index < 0)) {
            return "unknown";
        }
        return names[index];
        
    }
};

// specaialization for Fruit
template <> const int Traits<Fruit>::max_len = 3;
template <> const string Traits<Fruit>::names[] = {"apple", "orange", "pear"};

// specialization for Color
template <> const int Traits<Color>::max_len = 3;
template <> const string Traits<Color>::names[] = {"red", "green", "orange"};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
