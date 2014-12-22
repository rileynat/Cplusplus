#include <iostream>
#include <cmath>

using namespace std;

int main () {
    
    double total = 0;
    double total2 = 0;
    for ( long long n = 11; n < 200000; n++ ) {
        double temp = log10(n*1.0);
        total += temp / (n*n*1.0);
        cout << temp / (n*n*1.0) << " " << total <<  endl;
    }
    for (int start; (start <= 10); start++);
    cout << "this" << endl;

    cout << "total is " << total << endl;
}
