#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
int main() {
	const double pi = M_PI;
	double a = 0;
	double b = 1;
	double x = a;
	double x_n = 0; 
	for (x = a; x <= b; x = x + 0.05) {
		x = round(x * 100) / 100;
		double i = 1;
		double sum = 0;
		double f = (x*sin(pi/4))/(1 - 2*x*cos(pi/4));
		x_n = std::pow(x, i)*sin(i*pi/4);
		while (abs(x_n) >= pow(10.0, -3.0)) {
			sum = sum + x_n;
			i = i + 1;
			x_n = std::pow(x, i)*sin(i*pi/4); 
		}
		std::cout << x << ' ' << sum << ' ' << f << std::endl;
	}
}
