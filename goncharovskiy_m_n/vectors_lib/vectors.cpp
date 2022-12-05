#include <iostream>
#include <cmath>
#include "vectors.h"

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
void print_Rdec(Rdec2D n) {
	std::cout << '(' << n.x << ',' << n.y << ')' << std::endl;
}
