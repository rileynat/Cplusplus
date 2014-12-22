#include <iostream>
#include <cstdlib>
using namespace std;

#define LINEAR_MAX 65536
#define LOG_LINEAR_MAX 65536//1048576

int main () {

    int arr1[LINEAR_MAX];
    int arr2[LOG_LINEAR_MAX];

    for ( int i = 0; i < LINEAR_MAX; i++ ) {
        arr1[i] = rand() % 2;
    }

    for ( int i = 0; i < LOG_LINEAR_MAX/2; i++ ) {
        arr2[i] = 0;
    }
    for ( int i = LOG_LINEAR_MAX/2; i < LOG_LINEAR_MAX; i++ ) {
        arr2[i] = 1;
    }

    for ( int i = 0; i < LINEAR_MAX; i++ ) {
        if ( arr1[i] ) {
            cout << arr1[i] << " " << endl;
        }
    }    
}
