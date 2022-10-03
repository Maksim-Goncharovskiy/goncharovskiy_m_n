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
	double a = -1;
	double b = 1;
	double x = a;
	double x_n = 0;
	for (x = a; x <= b; x = x + 0.1) {
		x = round(x * 10) / 10;
		double i = 0;
		double sum = 0;
		double f = cos(x);
		while (true) {
			x_n = std::pow(-1.0, i) * std::pow(x, 2 * i) / factorial(2 * i);
			if (abs(x_n) >= pow(10.0, -3.0)) {
				sum = sum + x_n;
				i = i + 1;
			}
			else {
				break;
			}
		}
		std::cout << x << ' ' << sum << ' ' << f << std::endl;
	}
}
