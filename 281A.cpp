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
    line[0] = toupper(line[0]);
    cout << line;
	return 0;

}