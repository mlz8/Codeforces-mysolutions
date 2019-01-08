#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> counts(4, 0);
	for (auto i = 0; i < n; i++) {
		int aux;
		cin >> aux;
		counts[aux-1]++;
	}
	int res = counts[3] + counts[2]; // 4 + 3

	// all 1s go to 3
	int ones = max(counts[0]-counts[2], 0);
	// cout << ones<<endl;
	// remaining 1s, 2s
	res += ceil((ones+2*counts[1])/4.0);
	cout << res;
	return 0;

}