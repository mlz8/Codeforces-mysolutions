// my first program in C++
#include <iostream>
#include <map>
#include <string>

using namespace std;



class Pair {
public:
	Pair(int x, int y) : first(x), second(y) {} 
	Pair() : first(0), second(0) {} 
	Pair(int x) : first(x), second(0) {} 


	int first, second;
};


void toString(map<string, Pair> &t) {
	cout << "///"<<endl;
	for(auto& x : t) {
		cout << x.first << ", " << x.second.first << " " << x.second.second <<endl;
	}
	cout << "///"<<endl;
}


int main()
{
	int n;
	cin >> n;
	map<string, Pair> t;
	string maxName = "";
	int maxPoints = -1;
	int maxInd = n+1;

	
	for( int i =0 ; i < n; i++) {
		// cout << "----------" << endl;
		string name;
		int points;
		cin >> name >> points;
		bool found = 0; 
		for(auto& x : t) {
			if (!x.first.compare(name)) {
				x.second.first += points; found = 1;
				if (x.second.first > maxPoints) {
					x.second.second = i;
					maxPoints = x.second.first;
					maxName = x.first;
					maxInd = x.second.second;
				} else if (x.second.first == maxPoints) {
					x.second.second = i;
					if (x.second.second < maxInd) {
						// cout << "in if" << x.second.second << " " << maxInd << endl;
						maxInd = x.second.second;
						maxName = x.first;
					} else {
						// cout << "in else" << endl;
						for(auto& aux : t) {
							if(aux.second.second < maxInd && maxPoints == aux.second.first) {
								maxName = aux.first;
								maxInd = aux.second.second;
							}
						}	
					}
				} else if(!maxName.compare(name) && points < 0) {
					maxPoints = x.second.first;
					maxInd = x.second.second;


					for(auto& aux : t) {
						if (aux.second.first > maxPoints) {
							maxPoints = aux.second.first;
							maxName = aux.first;
							maxInd = aux.second.second;
						} else if (aux.second.first == maxPoints && aux.second.second < maxInd) {
							maxPoints = aux.second.first;
							maxName = aux.first;
							maxInd = aux.second.second;							
						}
					}
					
				}
			}
			// toString(t);
					// cout << " fin " << maxName << " with " << maxPoints << endl;

					// cout <<"maxName:" << maxName << endl;
		}

		if (!found) {
			t[name] = Pair(points, i);

			if (points > maxPoints) {
				maxPoints = points;
				maxName = name;
				maxInd = i;
			}

		}

	}

	// cout << "----------" << endl;
	// toString(t);
	cout << maxName << endl;

	return 0;

}