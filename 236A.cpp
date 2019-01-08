#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <set> 

using namespace std;



int main() {
	string username;
	cin >> username;
	set<char> letters;
	for (auto i = 0; i < username.length(); i++) {
		letters.insert(username[i]);
	}
	if (letters.size() % 2 == 0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";
	return 0;

}