#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
double factorial(double x) {
	double ans = 1;
	for (double i = 1; i <= x; i++) {
		ans = ans * i;
	}
	return ans;
}

int main() {
	const double e = M_E;
	double a = 0;
	double b = 1;
	double x = a;
	double x_n = 0;
	for (x = a; x <= b; x = x + 0.1) {
		x = round(x * 10) / 10;
		double i = 0;
		double sum = 0;
		double f = pow(e, 2 * x);
		x_n = std::pow(2 * x, i) / factorial(i);
		while (abs(x_n) >= pow(10.0, -4.0)) {
			sum = sum + x_n;
			i = i + 1;
			x_n = std::pow(2 * x, i) / factorial(i);
		}
		std::cout << x << ' ' << sum << ' ' << f << std::endl;
	}
}
