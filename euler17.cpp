#include <iostream>
#include <string>
#include "external_lib.h"

using namespace std;

int word_count ( string str ) {
	int letter_count = 0;
	for ( string::iterator it = str.begin() ; it < str.end(); it++ ) {
         if ( *it < 123 && *it > 64 ) {
         	letter_count++;
         }
    }
    return letter_count;
}

int main () {

	int total = 0;
	for ( int i = 1; i < 1000; i++ ) {
		total += word_count(num_to_string_thou(i) );
	}
	cout << total << endl;
}
