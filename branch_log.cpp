#include <iostream>
#include <cstdlib>
using namespace std;

#define LOG_LINEAR_MAX 65536//1048576
#define LINEAR_MAX 65536

int main () {

    int arr1[LOG_LINEAR_MAX];
    int arr2[LINEAR_MAX];

    for ( int i = 0; i < LINEAR_MAX; i++ ) {
        arr2[i] = rand() % 2;
    }

    for ( int i = 0; i < LOG_LINEAR_MAX/2; i++ ) {
        arr1[i] = 0;
    }
    for ( int i = LOG_LINEAR_MAX/2; i < LOG_LINEAR_MAX; i++ ) {
        arr1[i] = 1;
    }

    for ( int i = 0; i < LOG_LINEAR_MAX; i++ ) {
        if ( arr1[i] ) {
            cout << arr1[i] << " " << endl;
        }
    }
}
