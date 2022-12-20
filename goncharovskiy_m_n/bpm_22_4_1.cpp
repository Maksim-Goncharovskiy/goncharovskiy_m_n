#include <iostream>
#include <cmath>
double factorial(double i) {
	double res = 1;
	while (i > 0) {
		res = i * res;
		i = i - 1;
	}
	return res;
}

double Sum(double x) {
	double eps = 0.0001;
	double i = 0;
	double s1 = pow(x, 2*i)/(factorial(2*i));
	double result = 0;
	while (s1 - eps >= 0) {
		result = result + s1;
		i = i + 1;
		s1 = pow(x, 2 * i) / (factorial(2 * i));
	}
	return result;	
}

int main() {
	double a = 0.1;
	double b = 1.01;
	for (double x = a; x <= b; x += 0.05) {
		std::cout << x << " " << Sum(x)<<std::endl;
	}
}
