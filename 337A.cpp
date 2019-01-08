#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <sstream>

using namespace std;


int main() {
	int n, m;
	cin >> m >> n;

	vector<int> nrs;
	for(auto i = 0; i < n; i++) {
		int aux; cin >> aux;
		nrs.push_back(aux);
	}
	sort(nrs.begin(), nrs.end());
	int best = nrs[nrs.size()-1] - nrs[0];
	for(auto i = 0; i < n-m+1; i++) {
		// cout << nrs[i] << " "<<nrs[i+m-1]<<"="<<nrs[i+m-1]-nrs[i] <<endl;
		if(nrs[i+m-1] - nrs[i] < best) {
			best = nrs[i+m-1] - nrs[i];
		}
	}
	cout << best;

	
	return 0;

}