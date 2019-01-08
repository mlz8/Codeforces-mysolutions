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

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return abs(v[i1]) < abs(v[i2]);});

  return idx;
}

int main() {
	string exp;
	cin >> exp;

	int c = 0;
	int nr_open = 0;
	for(int i = 0; i < exp.size(); i++) {
		c+= exp[i] == '?';
	}
	cout << c;

	vector<int> scores1, scores2;
	int aux1, aux2;
	while (c) {
		cin >>aux1>> aux2;
		scores1.push_back(aux1);
		scores2.push_back(aux2);
		c--; 
	}

	vector<int> res;
	for (int i = 0; i < scores2.size(); i++) {
		res.push_back((scores2[i] - scores1[i]));
	}
	
	cout << "nr open" << nr_open << endl;
	
	vector<size_t> ind = sort_indexes(res); 
	string ret = "";
	for (size_t i = 0; i < exp.size(); i++) {
		if (exp[i] != '?') {
			cout << "if"<<endl; 

			if  (exp[i] == '(') {
				nr_open++;
			} else {
				nr_open--;
			}
			ret += exp[i];
		} else {
			cout << "else"<<endl; 
			if (nr_open >= 0) {
				if (exp[i] >= 0) {
					ret += "(";
					nr_open++;
				} else {
					ret += ")";
					nr_open--;
				}
			} else {
				ret += ")";
				nr_open--;
			}
		}
	}
	ret += 'a';
	cout << ret; 	
	return 0;

}