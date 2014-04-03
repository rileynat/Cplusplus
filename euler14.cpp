#include <iostream>

using namespace std;

long long sequence_num( long long n ) {
	//cout << n<< " ";
	long long count = 0;
	while ( n != 1 ) {
		if ( n % 2 == 0 ) {
			n = n * 0.5;
			//cout << n << " "; 
			count++;
		} else  {
			n = 3 * n + 1;
			//cout << n<< " ";
			count++;
		}
	}
	//cout << endl;
	return count;
}


int main (int argc, const char* argv[]) {

	 long long cur_max = sequence_num(999999);
	
	 for ( long long i = 999998; i > 0; i-- ) {
		if ( i % 2 != 0 ) {
			long long num = sequence_num(i);
			if ( num > cur_max ) {
				cur_max = num;
				cout << i << " " << num << endl;
			}
		}
		if ( i % 1000 == 0 ) {
			cout << "marker " << i << endl;
		}
	}
}