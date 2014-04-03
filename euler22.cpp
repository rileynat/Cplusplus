#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int letter_count( string str ) {
	int total = 0;
	for ( auto it = str.begin(); it != str.end(); it++ ) {
		total += *it - 'A' + 1;
	}
	return total;
}


int main () {

	string filename = "names.txt";
	ifstream filestream;
	filestream.open( filename.c_str() );
	if ( ! filestream.is_open() ) {
		cerr << "open failed with filename " << filename << endl;
		exit(1);
	}
	
	
	string name = "";
	vector<string> names_array;
	while ( filestream >> name ) {
		names_array.push_back(name);
	}
	
	sort(names_array.begin(), names_array.end());
		
	// string outfilename = "names_sorted.txt";
// 	ofstream out;
// 	out.open( outfilename.c_str() );
// 	if ( !out.is_open() ) {
// 		cerr << "open failed with filename " << filename << endl;
// 		exit(1);
// 	}
// 	name = "COLIN";
// 	cout << letter_count(name) << endl;
	long long total = 0;
	for ( int i = 0; i < names_array.size(); i++ ) {
		int index = i + 1;
		total += index * letter_count(names_array[i]);
		cout << total << endl;
	}
	cout << total << endl;
	
}