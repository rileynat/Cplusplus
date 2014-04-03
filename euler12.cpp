#include <iostream>

using namespace std;


long num_divisors( long n ) {
	long sum = 0;
	for ( long i = 1; i <= n; i++ ) {
		if ( n % i == 0 ) {
			++sum;
		}
	}
	return sum;
}

int main () {

	for ( long i = 1; true; i++ ) {
		long tri_num = i * (i + 1) * 0.5;
		if ( tri_num % 2 == 0 && num_divisors( tri_num ) > 500 ) {
			cout << tri_num << endl;
			break;
		}
	}
}
