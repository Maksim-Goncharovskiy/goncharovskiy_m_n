#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
	double r = 0;
	double n = 0;
	double R = 0;
	const double pi = M_PI;
	std::cin >> n >> r;
	double sinus = std::sin(pi / n);
	R = r * (sinus / (1 - sinus));
    std::cout << std::fixed << std::setprecision(8) << R;
}
