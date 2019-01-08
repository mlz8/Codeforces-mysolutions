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
  
  long long n;
  cin >> n;

  set<long long> nrs;

  for(auto i = 1; i <= sqrt(n); i++) {
    if(n%i == 0) {
      long long x = n/i;
      long long res = i * (x*(x-1))/2 + x;
      nrs.insert(res);
      res = x * (i*(i-1))/2 + i;
      nrs.insert(res);
    }
  }
  for(auto x:nrs) {
    cout << x << " ";
  }
  
	return 0;
}