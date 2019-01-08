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
	int n, m;
	cin >> n >> m;
	if(n < k) {
		cout << "NO"; return 0;
	}
	
	vector<int> bits;
	int counter = 0, nr = 0, aux = 0;
	while(n != 0) {
		bool bit = n % 2;
		nr += bit;
		bits.push_back(bit);
		n = n/2;
		counter++;
	}

	if(nr > k) {
		cout << "NO"; return 0;
	}
	cout << "YES" << endl;

	for(int i = bits.size(); i > 0; i--) {
		// cout << nr << endl;
		if(bits[i-1]) {
			int m = min(k - nr, bits[i-1]);
			nr += m;
			bits[i-1] -= m;
			bits[i-2] += 2*m;
		}
		for(auto j = 0; j < bits[i-1]; j++)
			cout << (int)pow(2, i-1) << " ";
	}
	// nr = 1;

	// cout << nr;

	return 0;
}