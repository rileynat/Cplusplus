#include <iostream>

using namespace std;


bool isPrime (unsigned long long n ) {
  for (unsigned long long i = 2; i < n * 0.5 + 1; i ++ ) {
    if (n % i == 0 && i != n)
      return false;
  }
  return true;
}

int main () {

  unsigned long long total = 0;
  for (unsigned long long i = 2; i < 2000000; i++ ) {
    cout << i << endl;    
    if (isPrime(i) ) {
      total += i;
      cout << "total is = " << total << endl;
    }
  } 
  cout << endl;
  cout << endl;
  cout << total << endl;
}
