#include <iostream>
#include <vector>

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

	vector<bool> bit_vector(28225, true);
	vector<int> abundant_nums;
	
	for ( int i = 11; i < 28500; i++ ) {
		if ( i < sum_of_divisors(i) ) {
			abundant_nums.push_back(i);
		}
	}
	
	for ( auto it = abundant_nums.begin(); it != abundant_nums.end(); it++ ) {
		for ( auto iter = abundant_nums.begin(); iter != abundant_nums.end(); iter++ ) {
			int sum = *it + *iter;
			if ( sum < 28225 ) {
				bit_vector[sum] = false;
			}
		}
	}
	
	int total = 0;
	for ( int i = 0; i < bit_vector.size(); i++ ) {
		if ( bit_vector[i] ) {
			cout << i << endl;
			total += i;
		}
	}
	
	cout << total << endl;
	
}