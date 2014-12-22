#include <iostream>
using namespace std;

int find_shift_of_sorted_array( int* array, int size ) {
	int* start = array;
	int* end = array + size - 1;
	while ( true ) {
		int* middle = start + (end - start) / 2;
		if ( middle == start ) {
			return end - array;
		}
		if ( *middle > *start ) {
			start = middle;
		}
		else if ( *middle < *end ) {
			end = middle;
		}
	}
}
