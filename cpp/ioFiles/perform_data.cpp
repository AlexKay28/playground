#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

vector<int> getValues(string s){
    vector<int> values;
    stringstream ss(s);

    while(ss.good()){
        string substr;
        getline(ss, substr, ',');
        values.push_back(stoi(substr));
    }
    return values;
}

void calc_squares(){
    int area;
    string numbers;

    vector<vector<int>> values;
    vector<int> answers;

    string str, data;
    string path_data = "./data/dataa.txt";
    string path_results = "./data/results.txt";
    fstream fs_data, fs_result;

    fs_data.open(path_data, fstream::in);
    fs_result.open(path_results, fstream::out | fstream::trunc);

    if ((fs_data.is_open()) && (fs_result.is_open())){
        while(getline(fs_data, str)){
            numbers = str.c_str();
            values.push_back(
              getValues(numbers)
            );
        }
        fs_result << "val1," << "val2," << "result\n";
        for (auto val: values){
            fs_result << val[0]
                      << ","
                      << val[1]
                      << ","
                      << val[0]*val[1]
                      << endl;
        }
    } else {
        printf("Error while file opening\n");
    }
    fs_data.close();
    fs_result.close();
}
