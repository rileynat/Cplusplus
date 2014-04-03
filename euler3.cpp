#include <iostream>
using namespace std;

int main () {

  long long GIVEN = 997799;
  for (long long i = 2; i < GIVEN / 2; i++) {
    if (GIVEN % i == 0) {
      bool flag = false;
      cout << i << endl;
      for (long long j = 2; j < i; j++) {
	//cout << " " << j << endl;
	if (i % j == 0) {
	  flag = true;
	  cout << " " << j << endl;
	}
      }
      if (!flag) {
	cout << "i = "<< i << endl;
      }
    }
  }
}
