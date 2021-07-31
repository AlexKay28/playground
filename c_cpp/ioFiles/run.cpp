#include <iostream>
#include "utils/perform_data.h"
#include "utils/create_data.h"
using namespace std;


int main() {
    int min, max, n_examples;

    cout << "Input n_examples, min, max values: ";
    cin >> n_examples >> min >> max;

    string data_path = "data/data.txt";
    string result_path = "data/results.txt";

    create_data(data_path, n_examples, min, max);
    calc_areas(data_path, result_path);
}
