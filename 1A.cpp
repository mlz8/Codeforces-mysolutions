#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int main() {
	int n, m, a; 
	cin  >> n >> m >> a;
	long long resRow = n/a;
	long long resCol = m/a;
	if (n % a != 0)
		resRow++;
	if (m % a != 0)
		resCol++;
}
	cout << resRow * resCol << endl;

