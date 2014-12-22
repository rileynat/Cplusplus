#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void genPerms( vector<char> s, queue<char> q, unsigned int min_length, unsigned int max_length, unsigned int str_length ) {
    if ( q.size() < str_length - max_length && q.size() > str_length - min_length ) {
        for ( unsigned int i = 0; i < s.size(); i++ ) {
            cout << s[i] << " ";
        }
    }

    for ( unsigned int i = 0; i < q.size(); i++ ) {
        s.push_back(q.front());
        q.pop();
        genPerms( s, q, min_length, max_length, str_length );
        q.push(s.front()
    }
}