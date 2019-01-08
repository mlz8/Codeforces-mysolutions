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
	int k,n,w; 
	cin >> k >> n >> w;
	int total = k * w * (w+1) / 2;
	cout << max(total - n,0);

	return 0;

}