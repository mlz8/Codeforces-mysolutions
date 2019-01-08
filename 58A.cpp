#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	string line;
	cin >> line;
	string temp = "hello";
	int index = 0;
	for (auto i = 0; i < line.length() && index < temp.length(); i++) {
		if(line[i] == temp[index]) {
			index++;
		}
	}
	if (index == temp.length())
		cout << "YES";
	else
		cout << "NO";
	return 0;

}