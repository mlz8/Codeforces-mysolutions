#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <set> 
#include <sstream>
#include <iterator>    
#include <bits/stdc++.h> 

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


int main() {   
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  long long sx=0, sy=0;
  for(auto i = 0; i < 2*n; i++) {
    int tempx, tempy; cin >> tempx >> tempy;
    sx += tempx; sy += tempy;
  }
  cout << sx/n << " " << sy/n;

	return 0;
}