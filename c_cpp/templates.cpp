#include <iostream>
using namespace std;

template <typename T1, typename T2> T2 add(T1 a, T2 b){
    return a + b;
}

int main(){

  int a;
  float b;
  a = 1; b = 2.3;

  printf("numbers: %i, %f \n", a, b);
  printf("their summs: %f \n", add(a, b));
  return 0;
}
