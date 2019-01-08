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
	int aux; cin >> aux;
	
	vector<int> lucky_nrs = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

	for(auto l: lucky_nrs) {
		if (aux % l == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	
	return 0;

}