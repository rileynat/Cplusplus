#include <iostream>
using namespace std;

bool isPrime (int n ) {
  for (int i = 2; i < n * 0.5+1; i ++ ) {
    if (n % i == 0 && i != n)
      return false;
  }
  return true;
}


int main () {

  int count = 6;
  for ( int i = 13; count < 11000; i ++ ) {
    if ( isPrime(i) ) {
      cout << i << "count is = " << count ++ << endl;
    }
  }
}