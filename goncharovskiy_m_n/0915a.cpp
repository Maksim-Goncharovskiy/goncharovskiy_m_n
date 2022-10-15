#include <iostream>
int main() {
	int n = 0;
	int k = 0;
	int max = 0; //максимальное ведро кратное длине сада
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		if (k % x == 0 && x > max) {
			max = x;
		}
	}
	std::cout << k / max;
}
