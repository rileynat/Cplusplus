#include <iostream>

using namespace std;


int sum_of_divisors( int n ) {

	int total = 0;
	for ( int i = 1; i < n / 2 + 1; i++ ) {
		if ( n % i  == 0 ) {
			total += i;
		}
	}
	return total;
}



int main () {

	int total = 0;
	
	for ( int i = 2; i < 10000; i++ ) {
	
		int a = sum_of_divisors(i);
		int b = sum_of_divisors(a);
		if ( i == b && a != i ) {
			total += i;
		}
	}

	cout << total << endl;

}