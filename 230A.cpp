#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <sstream>
#include <iterator>    

using namespace std;
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    copy (v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

struct Dragon {
	Dragon(int _level, int _gain) : level(_level), gain(_gain) {

	}
	int level, gain;
};
bool compare(const Dragon &a, const Dragon &b) {
	if (a.level == b.level)
		return a.gain < b.gain;
    return a.level < b.level;
}
int main() {
	int s, n;
	cin >> s>>n;

	vector<Dragon> dragons;
	for(auto i = 0; i < n; i++) {
		int aux1, aux2; cin >> aux1 >> aux2;
		dragons.push_back(Dragon(aux1, aux2));
	}

	sort(dragons.begin(), dragons.end(), compare);
	for(auto d:dragons) {
		if (s <= d.level) {
			cout << "NO";
			return 0;
		} else {
			s += d.gain;
		}
	}
	cout << "YES";
	
	return 0;

}