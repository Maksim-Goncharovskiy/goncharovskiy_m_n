#include <iostream>
#include <cmath>
int main(){
	double n = 0;
	std::cin >> n;
	double counter = 0;
	for (int i = 0; i < n; i++) {
		double x = 0;
		double y = 0;
		std::cin >> x >> y;
		if ((y >= x + 1) && (pow(x, 2) + pow(y, 2) <= 1)) {
			counter += 1;
		}
		else if ((y <= x - 1) && (pow(x, 2) + pow(y, 2) <= 1)) {
			counter += 1;
		}
	}
	std::cout << counter / n;
}
