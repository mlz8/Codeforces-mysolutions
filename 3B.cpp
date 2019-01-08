// my first program in C++
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ostream>
#include <time.h>
#include <numeric>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

using namespace std;

class Boat {
public:
	Boat(int id, int cap) 
		: id(id), cap(cap) {} 
	

	int id, cap;
};
std::ostream& operator << (std::ostream& os, const Boat& v) 
{
	os << "("<<v.id+1 << "-" << v.cap <<")";
    // for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    // {
    //     os <<*ii+1<<" ";
    // }
    return os;
}
template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os <<*ii+1<<" ";
    }
    return os;
}
struct comparator {
 bool operator()(Boat &b1, Boat &b2) {
 return b1.cap > b2.cap;
 }
};


int main() {
	int n, vol;
	cin >> n >> vol;
	vector<Boat> boats1, boats2; 
	for(size_t i=0; i < n; i++) {
		int aux1, aux2;
		cin >> aux1 >> aux2;
		if (aux1 == 1)
			boats1.push_back(Boat(i, aux2));
		if (aux1 == 2)
			boats2.push_back(Boat(i, aux2));
		if(n==5000 && vol == 3649) {
			if (i+1 == 4426) {
				cout << i << " " << aux1 << " " << aux2;
			}
		}
			
	}
	sort(boats1.begin(), boats1.end(), comparator()); 
	sort(boats2.begin(), boats2.end(), comparator()); 

	bool fin = (boats1.size() == 0 || boats2.size() == 0) || vol == 0;

	int gain = 0;
	vector<int> ids;
	int i=0, j=0;
	if(n==5000 && vol == 3649) {

		cout << boats1[i] << " " << boats1[i+1]<< " " << boats1[i+2]<< " " << boats1[i+3]<<endl;
		cout << boats2[i] << " " << boats2[i+1] << " " << boats2[i+2] << " " << boats2[i+3]<<endl;

	}
	while (!fin) {
		if (vol == 1 || boats1[i].cap > boats2[j].cap) {
			if(n==5000 && vol == 3649) {
				cout <<"1:"<<boats1[i]<<endl;
			}
			gain += boats1[i].cap;
			ids.push_back(boats1[i].id);
			vol -= 1;
			i++;

		} else if (i < boats1.size()-1 && boats1[i].cap + boats1[i+1].cap > boats2[j].cap) {
			if(n==5000 && vol == 3649) {
				cout << "2:"<<boats1[i] << " " << boats1[i+1]<<endl;
			}

			gain += boats1[i].cap+boats1[i+1].cap;
			vol -= 2;
			ids.push_back(boats1[i].id);
			ids.push_back(boats1[i+1].id);
			i+=2;
		} else {
			if(n==5000 && vol == 3649) {
				cout << "3:"<<boats2[j] <<endl;
			}
			gain += boats2[j].cap;
			ids.push_back(boats2[j].id);
			vol -= 2;			
			j++;

		}
		
		fin = (i > boats1.size()-1 || j>boats2.size()-1) || vol == 0;
	}
	for(size_t k=i; k<boats1.size() && vol > 0; k++) {
		gain += boats1[k].cap;
		ids.push_back(boats1[k].id); vol--;
	}

	for(size_t k=j; k<boats2.size() && vol > 1; k++) {
		gain += boats2[i].cap;
		ids.push_back(boats2[k].id); vol -= 2;
	}

	
  	cout << gain<<endl;
  	cout << ids;
  	return 0;

}