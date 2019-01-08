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



vector<int> dfs(const vector<vector<int>>& parent_to_child,  
	const vector<int>& colorsd, int current) {

	vector<int> colors;
	colors.push_back(colorsd[current]);
	for(auto node: parent_to_child[current]) {
		vector<int> aux = dfs(parent_to_child, colorsd, node);
		if (aux.size() == 1 && colors[0] == aux[0]) {
		} else {
			if (aux[0] == colors[0])
				colors.insert(colors.end(), aux.begin()+1, aux.end());
			else
				colors.insert(colors.end(), aux.begin(), aux.end());
		}
	}
	return colors;
}

int main() {   
	int n;


	cin >> n;
	vector<vector<int>> parent_to_child(n, vector<int>(0, 0));
	vector<int> colors;
	for(auto i = 2; i <= n; i++) {   
		int x; cin >> x;
		parent_to_child[x-1].push_back(i-1);
	}
	for(auto i = 1; i <= n; i++) {   
		int x; cin >> x;
		colors.push_back(x);
	}

	vector<int> res = dfs(parent_to_child, colors, 0);
	cout << res.size();
	return 0;
}