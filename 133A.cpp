#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;


int main()
{
	
	string str;
	cin >> str;
	for(auto s : str) {
		if(s == 'H'||s == 'Q'||s == '9') {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;

}