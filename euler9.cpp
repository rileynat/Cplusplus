#include <iostream>
#include <cmath>

using namespace std;


int main () {

  int first = 1;
  int second = 2;

  while (first < 1000) {

    second = 1;
    while (second < 1000) {
      
      double squareRoot = sqrt(first*first*1.0 + second*second*1.0);
      //      cout << squareRoot << " " << first << " " << second << endl;
      //if ( squareRoot == (int)squareRoot ) {
	//cout << first << " " << second << endl;
	//      }
      if ( first * 1.0 + second * 1.0 + squareRoot == 1000) {
	cout << first << " " << second << endl;
      }
      second++;
    }
    first++;
  }

}
