void genPerms(queue<unsigned int> &q, stack<unsigned int> &s, bool &b, const vector<vector<bool> >& graph_a, const vector<vector<bool> >& graph_b) {
  ///if (b == true)
    //return;
  if (q.empty()) {
    //b = run_adj_checks(s, graph_a, graph_b);
    cout << "s is " << endl;
    stack<unsigned int> s2 = s;
    for (unsigned int i = 0; i < s.size(); i++) {
      cout << s.front() << " ";
      s.pop();
    }
    cout << endl;
    return;
  }
  for (unsigned int i = 0; i < q.size(); i++) {
    s.push(q.front());
    q.pop();
    genPerms(q, s, b, graph_a, graph_b);
    q.push(s.top());
    s.pop();
  }
}