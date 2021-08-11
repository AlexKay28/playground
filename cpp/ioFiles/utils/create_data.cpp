#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

template <typename T> T get_random(T min, T max){
    assert(min < max);
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(min, max); // distribution in range [1, 6]
    return dist(rng);
}

void create_data(string path, int n_examples=5, int min=10, int max=100){
    // this function creates dataset for "calculate area" task
    int rand1, rand2;
    string str;
    fstream fs;

    fs.open(path, fstream::in | fstream::out | fstream::trunc);
    if (fs.is_open()){
        while(n_examples--){
            rand1 = get_random(min, max - 1);
            rand2 = get_random(rand1, max);
            str = std::to_string(rand1) + "," + std::to_string(rand2) + '\n';
            fs << str;
        }
    } else {
        printf("Error while file opening\n");
    }
    fs.close();
}
