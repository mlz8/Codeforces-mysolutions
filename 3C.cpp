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

vector<vector<int>> toInt(vector<vector<char>>& arr) {
	vector<vector<int>> res;

	for(const auto &line : arr) {
		vector<int> aux;
		for(const auto &a : line) {
			if(a == '.') {
				aux.push_back(0);
			} else if (a == 'X') {
				aux.push_back(1);
			} else {
				aux.push_back(-1);
			}
		}
		res.push_back(aux);
	}
	return res;
}
template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int checkFin(const vector<vector<int>> &res) {
	bool x=0, y=0;
	for(size_t i=0; i < 3; i++) {
		int nr = 0;
		for(size_t j=0; j < 3; j++) {
			nr += res[i][j];
		}
		if (nr==-3) {
			y=1; 
		}
		if (nr==3) {
			x=1;
		}
	}
	for(size_t i=0; i < 3; i++) {
		int nr = 0;
		for(size_t j=0; j < 3; j++) {
			nr += res[j][i];
		}
		if (nr==-3) {
			y=1;
		}
		if (nr==3) {
			x=1;
		}
	}
	int nr = 0;
	for(size_t i=0; i < 3; i++) {
		nr += res[i][i];
	}
	if (nr==-3) {
		y=1; 
	}
	if (nr==3) {
		x=1;
	}
	nr = 0;
	for(size_t i=0; i < 3; i++) {
		nr += res[i][3-i-1];
	}
	if (nr==-3) {
		y=1; 
	}
	if (nr==3) {
		x=1;
	}
	if(x && y) return -2;
	if(x) return 1;
	if(y) return -1;
	return 0;
}

int diff(const vector<vector<int>> &res) {
	int nrx = 0, nry=0;
	for(size_t i=0; i < 3; i++) {
		for(size_t j=0; j < 3; j++) {
			if (res[i][j] == 1) 
				nrx++;
			if (res[i][j] == -1) 
				nry++;
		}
	}
	if(nrx == nry) return 1;
	if(nrx == nry+1) return -1;
	return 0;

}
bool gameover(const vector<vector<int>> &res) {
	for(size_t i=0; i < 3; i++) {
		for(size_t j=0; j < 3; j++) {
			if(res[i][j] == 0)
				return false;
		}
	}

	return true;
}

int main() {
	string l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	vector<vector<char>> arr;
	arr.push_back({l1[0], l1[1], l1[2]});
	arr.push_back({l2[0], l2[1], l2[2]});
	arr.push_back({l3[0], l3[1], l3[2]});
	vector<vector<int>> res = toInt(arr);
	int d = diff(res);
	int fin = checkFin(res);
	if (d == 0) {
		cout << "illegal";
	} else if (d==-1 && fin == -1) {
		cout << "illegal";
	} else if (d == 1 && fin == 1) {
		cout << "illegal";
	} else {
	if (fin == 1) {
		cout << "the first player won";
	} else if (fin == -1) {
		cout << "the second player won";
	} else if (fin == -2){
		cout << "illegal";
	} else {
		if(gameover(res)) {
			cout << "draw";
		} else if(d == 1) {
			cout << "first";
		} else if (d == -1) {
			cout << "second";
		} 
	}
	}
	return 0;

}