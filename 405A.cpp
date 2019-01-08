#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <sstream>
#include <iterator>    
// 3 2 1 2

// nr 3s, >=2s, 1s
// 1 		3  4  

// 4, 3, 2, 1
// 1, 1, 0, 1

// >=4, >=3, >=2, >=1
// 1, 2, 2, 3


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
	int n;
	cin >> n;

	vector<int> nrs;
	for(auto i = 0; i < n; i++) {
		int aux; cin >> aux;
		nrs.push_back(aux);
	}
	sort(nrs.begin(), nrs.end());
	for(auto i = 0; i < n; i++) {
		cout << nrs[i] << " ";
	}

	
	return 0;

}