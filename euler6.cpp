#include <iostream>
using namespace std;

int main () {

  int total = 0;
  for ( int i = 1; i <= 100; i++) {
    total += i*i;
  }
  cout << total << endl;

}
