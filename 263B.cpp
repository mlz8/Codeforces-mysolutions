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



int main() {   
	int n, k;
	cin >> n >> k;

	vector<int> squares(n);
	for(auto i = 0; i < n; i++) {   
		cin >> squares[i];
	}
	sort(squares.begin(), squares.end());
	k = squares.size() - k;
	
	int aux = squares[k];
	bool left = k==0 || (k > 0 && aux != squares[k-1]);
	bool right = (k == squares.size() - 1) || (k < squares.size() - 1 && aux != squares[k+1]);

	if(left && right) {
		cout << squares[k] << " " << squares[k];
	} else {
		cout << "-1";
	}

	return 0;
}