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

  vector<int> nrs;
  for(auto i = 0; i < n; i++) {
    string str; cin >> str;
    int left = 0, m = 0;
    for(auto s : str) {
      if(s == '(')
        left++;
      else
        left--;
      m = min(m, left);
    }
    if(m >= min(0, left)) {
      nrs.push_back(left);
    } 
  }
  sort(nrs.begin(), nrs.end());
  int i = 0, j = nrs.size()-1;
  int res = 0;
  while(i < j) {
    if(nrs[i] + nrs[j] == 0) {
      i++; j--; res++;
    } else if (nrs[i] > 0 || nrs[j] < 0) {
      break;
    } else if (abs(nrs[i]) < abs(nrs[j])) {
      j--;
    } else {
      i++;
    }
  }
  cout << res;
	return 0;
}
