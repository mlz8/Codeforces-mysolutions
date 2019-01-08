// my first program in C++
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ostream>


using namespace std;

class Pair {
public:
	Pair(int x, int y) : first(x), second(y) {} 
	Pair() : first(0), second(0) {} 
	Pair(int x) : first(x), second(0) {} 

	friend ostream &operator<<(std::ostream &os, const Pair& A);
	int first;
	int second;
};

ostream &operator<<(std::ostream &os, const Pair& A) { 
	return os << "(" << A.first << ", " << A.second << ")";
}

template<typename T>
void toString(vector<vector<T>> &M) {
	for(size_t i=0; i < M.size(); i++) {
		for(size_t j=0; j < M[0].size(); j++) {
			cout << M[i][j]<< " ";
		}
		cout << endl;
	}
}

int getPower(int a, int x) {
	int n = 0;
	int aux = x;

	while(a % aux == 0) {
		
		aux *= x;
		n++;
	}
	return n;
}




int main()
{
	int n;
	cin >> n;
	vector<vector<Pair>> res;
	res.resize(n, std::vector<Pair>(n));
	vector<vector<int>> m;
	m.resize(n, std::vector<int>(n, 0));
	for(size_t i=0; i < n; i++) {
		for(size_t j=0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	// toString(m); cout << endl;

	for(size_t i=0; i < n; i++) {
		for(size_t j=0; j < n; j++) {
			res[i][j].first = getPower(m[i][j], 2);
			res[i][j].second = getPower(m[i][j], 5);
		}
	}


	vector<vector<Pair>> ss;
	ss.resize(n, vector<Pair>(n));
	vector<vector<string>> st, st2;
	st.resize(n, vector<string>(n, ""));
	st2.resize(n, vector<string>(n, ""));

	ss[0][0] = res[0][0];	
	for(size_t i = 1; i < n; i++) { 
		ss[i][0].first = res[i][0].first + ss[i-1][0].first;
		ss[i][0].second = res[i][0].second + ss[i-1][0].second;
		
		st[i][0] = "D"+st[i-1][0];
		st2[i][0] = "D"+st2[i-1][0];

	}
	cout << n << endl;
	for(size_t j=1; j < n; j++) {
		for(size_t i=0; i < n; i++) {
			ss[i][j].first = res[i][j].first + ss[i][j-1].first;
			ss[i][j].second = res[i][j].second + ss[i][j-1].second;
			if (i != 0) {
			 	int first = res[i][j].first + ss[i-1][j].first;
				int second = res[i][j].second + ss[i-1][j].second;
				if (first < ss[i][j].first) {
					ss[i][j].first = first; // a[i][j] = aij;
					st[i][j] = st[i-1][j] + "D";
					
				} else {
					st[i][j] = st[i][j-1] + "R";
				}
				
				if (second < ss[i][j].second) {
					ss[i][j].second = second;
					st2[i][j] = st2[i-1][j] + "D";
					
				} else {
					st2[i][j] = st2[i][j-1] + "R";
				}



			} else {
				st[i][j] = st[i][j-1] + "R";
				st2[i][j] = st2[i][j-1] + "R";
			
			}


		}
	}
	cout << min(ss[n-1][n-1].first, ss[n-1][n-1].second) << endl;
	
	if(ss[n-1][n-1].first < ss[n-1][n-1].second)
		cout << st[n-1][n-1] << endl;
	else
		cout << st2[n-1][n-1] << endl;



	return 0;

}