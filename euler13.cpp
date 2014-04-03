#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main (int argc, const char * argv[] ) {
    string filename = "";
    ifstream filestream;
    
    if ( argv[1] ) {
        filename = (string)argv[1];
    }
    
    filestream.open( filename.c_str() );
    if ( !filestream.is_open() ) {
        cerr << "open failed: " << filename << endl;
        exit(1);
    }
    
    
    unsigned long long total = 0;
    string line = "";
    
    while ( getline(filestream, line ) ) {
        string substring = line.substr(41);
        //cout << substring << endl;

        unsigned long long num = static_cast<unsigned long long>(atoi( substring.c_str() ));
        cout << num << endl;
        total += num;
        //cout << total << endl;
    }
    cout << "total " << total << endl;
    
    filestream.close();
}
