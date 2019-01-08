#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <set> 
#include <sstream>
#include <iterator>    
#include <bits/stdc++.h> 

using namespace std;
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    copy (v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}


int main() {   
	int n, m;
	cin >> n >> m;

    unordered_set<string> poland, enemy;
    for(auto i = 0; i < n; i++) {
    	string temp; cin >> temp;
    	poland.insert(temp);
    }
	for(auto i = 0; i < m; i++) {
    	string temp; cin >> temp;
    	enemy.insert(temp);
    }

    int nr_common = 0;
    for(auto p: poland) {
    	nr_common += enemy.find(p) != enemy.end();
    }

    nr_common = nr_common % 2;

	if(n + nr_common > m) {
		cout << "YES";
	} else {
		cout << "NO";
	}



	return 0;
}