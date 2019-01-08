#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;


int main()
{
	
	int n;
	cin >> n;
	vector<int> nrs;
	int s = 0;
	for (auto i=0; i< n; i++) {
		int temp; cin >> temp;
		nrs.push_back(temp);
		s+=temp;
	}
	sort(nrs.begin(), nrs.end(), greater<int>());
	int todo = ceil(s/2);
	s=0;
	int res = 0;
	for(auto i = 0; i < n; i++) {
		s+=nrs[i];

		if(s > todo) {
			res = i+1;
			break;
		}
	}
	cout << res;
	return 0;

}