#include <iostream>
using namespace std;

int main () {
  
  int first = 999;
  int second = 999;
  while (first > 99) {
    //    cout << first << endl;
    second = 999;
    while (second > 99) {
      //cout << " " << second << endl;
      int multiple = first * second;
      //      cout << multiple << endl;
      if ( multiple / 100000 == multiple % 10) {
	if ( (multiple / 10000) % 10 == (multiple / 10) % 10) {
	  if ( (multiple / 1000) % 10 == (multiple / 100) % 10) {
	    cout << multiple << endl;
	  }
	}
      }
      second --;
    }
    first --;
  }
}