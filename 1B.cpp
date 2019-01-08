#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;
void convert(long long x) {
	x = x-1;
   if ( x < 26 ) {
      cout << char(int('A') + x);
      return;
   }

   int rem = x % 26;

   convert(x / 26);
   cout << char(int('A') + rem);
}


int main() {
	int n; 
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		string cell;
		cin >> cell;

		size_t C = 1;
        while (C < cell.length() && isdigit(cell[C]))
        {
            ++C;
        }

        if (C > 1 && C < cell.length()) {

		// if (cell[0] == 'R') {
			size_t j = 1;
			long long nr = 0, nr2 = 0;
			while (cell[j] != 'C') {
				nr *= 10;
				nr += (int)cell[j]-'0';
				j++;
			}
			j++;
			for (; j< cell.length(); j++) {
				nr2 *= 10;
				nr2 += (int)cell[j] - '0';
			}
			convert(nr2);
			cout << nr << endl;
		
		} else {
			stringstream ss;
			size_t j = 0;

			while (!isdigit(cell[j])) {
				ss << cell[j];
				j++;
			}
			long long nr = 0;
			for (; j< cell.length(); j++) {
				nr *= 10;
				nr += (int)cell[j] - '0';
			}
			cout << 'R' << nr;
			string chars = ss.str();
			long long nr2 = 0;
			for(size_t j = 0; j<chars.length(); j++) {
				nr2 = nr2 * 26 + ((int)chars[j] - 'A'+1);
			}
			cout<<'C' << nr2<<endl;

		}
	}
}

