#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;



int main()
{
	string line;
	cin >> line;
	vector<int> numbers;
	for (auto i=0; i < line.length(); i+=2) {
		numbers.push_back(line[i] - '0');
	}
	sort(numbers.begin(), numbers.end());
	for (auto i = 0; i < numbers.size()-1; i++) {
		cout << numbers[i] << "+";
	}
	cout << numbers[numbers.size()-1];
	
	return 0;

}