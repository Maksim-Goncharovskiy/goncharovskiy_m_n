#include <iostream>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
		std::cin >> a1 >> a2 >> b1 >> b2;
		cnt = a1 + a2 + b1 + b2;
		if (cnt == 0) {
			std::cout << 0 << std::endl;
		}
		else if (cnt <= 3) {
			std::cout << 1 << std::endl;
		}
		else {
			std::cout << 2 << std::endl;
		}
	}
}
