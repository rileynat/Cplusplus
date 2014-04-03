#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void genPerms(queue<char>& q, stack<char>& s, vector<string>& v) { 
	unsigned k, size=q.size();
	if (q.empty()) { 
		string str = "";
		stack<char> s2 = s;
		while ( !s2.empty() ) {
			str.append(1, s2.top());
			s2.pop();
		}
		v.push_back(str);
		return; 
	}
	for(k=0;k!=size;k++) {
		s.push(q.front()); q.pop(); 
		genPerms(q,s,v);
		q.push(s.top()); s.pop(); 
	}
}

int main () {

	//string str_array[] = { "210", "120", "012", "102", "021", "201" }
	vector<string> vector_str;
	
	stack<char> s;
	queue<char> q;
	q.push('A');
	q.push('B');//'B','C','D','E','F','G','H','I','J')
	q.push('C');
	q.push('D');
	q.push('E');
	q.push('F');
	q.push('G');
	q.push('H');
	q.push('I');
	q.push('J');
	
	genPerms(q, s, vector_str);
	
	sort(vector_str.begin(), vector_str.end());
	
 	for ( int i = 0; i < 1000002; i++ ) {
 		cout << "index: " << i + 1 << "string: " << vector_str[i] << endl;
 	}
}