#include <iostream>
using namespace std;

int swap_pointer(int * a, int * b){
    // pointers gets address of variable
    // but address was provided usign reference sigh. futher
    // we work with pointers with dereference ex: (*p)
    int temp;
    temp = *a; *a = *b; *b = temp;
}

int swap_reference(int& a, int& b){
    // swap reference just gets references on values
    // but futher we work with this directly
    int temp;
    temp = a; a = b; b = temp;
}

int main(){
  int a, b;
  a = 5; b = 15;

  printf("original: %i, %i \n", a, b);

  swap_pointer(&a, &b);
  printf("swap pointer: %i, %i\n", a, b);

  swap_reference(a, b);
  printf("swap reference: %i, %i\n", a, b);
  return 0;
}
