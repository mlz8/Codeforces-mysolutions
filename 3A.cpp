// my first program in C++
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ostream>
#include <time.h>
#include <numeric>
#include <algorithm>


using namespace std;



int main() {
	string inp, outp;
	cin >> inp >> outp;
	int x1, y1, x2, y2;
	x1 = (int)(inp[0]) - (int)('a');
	y1 = (int)(inp[1]) - (int)('0');
	x2 = (int)(outp[0]) - (int)('a');
	y2 = (int)(outp[1]) - (int)('0');

	int diffx = abs(x2 - x1);
	int diffy = abs(y2 - y1);
	int tog = min(diffx, diffy);
	int single = abs(diffx-diffy);  
	cout << tog + single<< endl;
	char xax = 'L', yax = 'U';
	if (x1 < x2) {
		xax = 'R';
	}
	if (y1 > y2) {
		yax = 'D';
	}
	for(size_t i=0; i < tog; i++) {
		cout << xax << yax << endl;
	}
	char fin = xax;
	if(diffx < diffy) {
		fin = yax;
	}
	for(size_t i=0; i < single; i++) {
		cout << fin << endl;
	}






	return 0;

}