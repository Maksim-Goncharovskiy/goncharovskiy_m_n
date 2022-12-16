#include <iostream>
#include <cmath>
#include "geom.h"

Rdec2D ToDec(Rpol2D n) {
	Rdec2D result;
	result.x = n.r * cos(n.phi);
	result.y = n.r * sin(n.phi);
	return result;
}
Rpol2D ToPol(Rdec2D n) {
	Rpol2D result;
	result.r = pow(pow(n.x, 2) + pow(n.y, 2), 0.5);
	result.phi = acos(n.x / (pow((pow(n.x, 2) + pow(n.y, 2)), 0.5)));
	return result;
}

double Norm(Rdec2D n) {
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
Rdec2D operator-(Rdec2D n) {
	Rdec2D result;
	result.x = -1 * n.x;
	result.y = -1 * n.y;
	return result;
}

Rdec2D operator*(Rdec2D n, double c) {
	Rdec2D result;
	result.x = n.x * c;
	result.y = n.y * c;
	return result;
}
Rdec2D operator*(double c, Rdec2D n) {
	Rdec2D result;
	result.x = n.x * c;
	result.y = n.y * c;
	return result;
}

Rdec2D operator/(Rdec2D n, double c) {
	Rdec2D result;
	result.x = n.x / c;
	result.y = n.y / c;
	return result;
}

bool operator==(Rdec2D n, Rdec2D m) {
	if (n.x == m.x && n.y == m.y) {
		return true;
	}
	else {
		return false;
	}
}
bool operator!=(Rdec2D n, Rdec2D m) {
	if (n.x != m.x || n.y != m.y) {
		return true;
	}
	else {
		return false;
	}
}

double Dot(Rdec2D n, Rdec2D m) {
	double result = n.x * m.x + n.y * m.y;
	return result;
}
void print(Rdec2D n) {
	std::cout << '(' << n.x << ',' << n.y << ')' << std::endl;
}
