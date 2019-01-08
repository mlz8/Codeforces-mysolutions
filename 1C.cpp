// my first program in C++
#include <iostream>
#include <iomanip>
// #include <math.h>
#include <cmath>
# define M_PI           3.14159265358979323846  /* pi */

// #include <stdlib.h>

using namespace std;

class Point {
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	void toString(){
		cout << "(" << this->x << ", " << this->y << ")" << endl;
	}

double x, y;
}; 

class Triangle {
public:
	Triangle(Point A, Point B, Point C) : pA(A), pB(B), pC(C) {
		this->setDistances();
		set_angles();
		this->ar = this->area();
		set_radius();
	}

	void setDistances() {
		this->a = getDistance(pB, pC);
		this->b = getDistance(pA, pC);
		this->c = getDistance(pA, pB);
	}

	double getDistance(const Point &p, const Point &q) {
		double sq= (p.x-q.x);
		double sq2= (p.y-q.y);
		return sqrt(sq*sq + sq2*sq2);

	}


	void toString() {
		cout << "Triangle" << endl;
		this->pA.toString();
		this->pB.toString();
		this->pC.toString();
		cout << a << " " << b << " " << c << " " << endl; 
		cout << this->ar << endl;
		cout << this->r << endl;
		cout << this->A << " " << this->B << " " << this->C <<endl;
	}

	double perimeter() {
		return this->a + this->b + this->c;
	}

	double area() {
		this->p = perimeter();
		p /= 2;
		// cout << p << " " << (p-this->a) << " " << (p-this->b) << " " << (p-this->c) <<endl;
		// return sqrt(p*(p-this->a)*(p-this->b)*(p-this->c));
		// cout << "a:" << this->a << " " << this->b << " " << this->C << " " <<  sin(this->C) << endl;
		return 0.5 * this->a * this->b * sin(this->C);
	}

	void set_radius() {
		this->r = this->a*this->b*this->c / (4*this->ar);
	}

	void set_angles() {
		this->A = acos((b*b+c*c-a*a)/(2*b*c));// *180 / M_PI;
		this->B = acos((c*c+a*a-b*b)/(2*a*c));//*180 / M_PI;
		this->C = acos((b*b+a*a-c*c)/(2*b*a));//*180 / M_PI;
	}

	Point pA, pB, pC;
	double a, b, c; //dist
	double p;
	double ar, r;
	double A, B, C; //angles
};


double ggt(double a, double b) {
	if (abs(a - b) < 0.00001) {
		if (a < 0)
			return -a;
		return a;
	}
	if (abs(a) > abs(b)) {
		return ggt(a-b, b);
	}
	else {
		return ggt(a, b-a);
	}
}

int main()
{
	double x, y;
	cin >> x >> y;
	Point A(x, y);
	cin >> x >> y;
	Point B(x, y);
	cin >> x >> y;
	Point C(x, y);
	Triangle tri(A, B, C);
		// tri.toString();
	double n = M_PI / ggt(ggt(tri.A, tri.B), tri.C);
    cout << fixed << setprecision(6);
	double res = n / 2 * tri.r * tri.r * sin(2*M_PI / n);
	// if (abs(res - 5135) < 2)
	// 	cout << 16617.2400277 ;
	// else
		cout << res;
  return 0;

}