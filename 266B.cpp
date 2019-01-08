#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <sstream>

using namespace std;


int main() {
	int n, t;
	cin >> n >> t;
	string str;
	cin >> str;
	for(auto j = 0; j < t; j++) {
		string res(str);
		for(auto i = 0; i < n-1; i++) {
			if(str[i] == 'B' && str[i+1] == 'G') {
				swap(res[i], res[i+1]);
			}
		}
		str = res;
	}
	cout << str;
	
	return 0;

}