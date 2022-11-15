#include <iostream>
#include <cmath>

struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};
struct Rpd2D {
	double r = 0.0;
	double phi = 0.0;
};

Rdec2D perevod1(Rpd2D n) {
	Rdec2D result;
	result.x = n.r * cos(n.phi);
	result.y = n.r * sin(n.phi);
	return result;
}
Rpd2D perevod2(Rdec2D n) {
	Rpd2D result;
	result.r = pow(pow(n.x, 2) + pow(n.y, 2), 0.5);
	result.phi = acos(n.x / (pow((pow(n.x, 2) + pow(n.y, 2)), 0.5)));
	return result;
}

double lengh(Rdec2D n) {
	return pow(pow(n.x, 2) + pow(n.y, 2), 0.5);
}
Rdec2D operator+(Rdec2D n, Rdec2D m) {
	Rdec2D result;
	result.x = n.x + m.x;
	result.y = n.y + m.y;
	return result;
}
Rdec2D operator-(Rdec2D n, Rdec2D m) {
	Rdec2D result;
	result.x = n.x - m.x;
	result.y = n.y - m.y;
	return result;
}
Rdec2D operator*(Rdec2D n, double c) {
	Rdec2D result;
	result.x = n.x * c;
	result.y = n.y * c;
	return result;
}
double dot(Rdec2D n, Rdec2D m) {
	double result = n.x * m.x + n.y * m.y;
	return result;
}

int main() {
	Rdec2D vector1;
	vector1.x = 4.0;
	vector1.y = 4.0;
	Rdec2D vector2;
	vector2.x = 5.0;
	vector2.y = 6.0;

	std::cout << "First vector: " << '(' << vector1.x << ',' << vector1.y << ')' << std::endl;
	std::cout << "Second vector: " << '(' << vector2.x << ',' << vector2.y << ')' << std::endl;
	
	Rdec2D a = vector1 + vector2;
	std::cout << "Sum: " << '(' << a.x << ' ' << a.y << ')' << std::endl;
	
	a = vector1 - vector2;
	std::cout << "Dec: " << '(' << a.x << ' ' << a.y << ')' << std::endl;
	
	a = vector1 * 3;
	std::cout << "Mul: " << '(' << a.x << ' ' << a.y << ')' <<  std::endl;

	double ans = dot(vector1, vector2);
	std::cout << "Dot: " << ans << std::endl;

	Rpd2D b = perevod2(vector1);
	std::cout << b.r << ' ' << b.phi;
}
