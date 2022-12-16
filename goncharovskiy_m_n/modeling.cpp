#include <geom/geom.h>
#include <iostream>
#include <cmath>
#include <fstream>
int main() {
	struct jojo 
	{
		Rdec2D r = {0, 10};
		Rdec2D v = {0.3953, 0};
		Rdec2D a = {0, 0};
	};
	std::fstream file;
	file.open("data.csv");
	file.clear();
	double const c = 1;
	jojo point;
	Rdec2D g;
	Rdec2D& a1 = point.a;
	Rdec2D& r1 = point.r;
	Rdec2D& v1 = point.v;
	double t = 1;
	for (int i = 0; i < 1000; i++) {
		g = -r1  * (1 / Norm(r1)) * (1 / pow(Norm(r1), 2));
		v1 = v1 + g * t + a1 * t;
		r1 = r1 + v1 * t;
		file << r1.x <<";"<<r1.y<<std::endl;
	}
}
