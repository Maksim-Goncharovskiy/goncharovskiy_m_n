//Заурядные числа
#include <iostream>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		std::cin >> n;
		int count = 0;
		int x = 1;
		while (x <= n) {
			count = count + 1;
			for (int k = 2; k < 10; k++) {
				if (x * k <= n) {
					count = count + 1;
				}
			}
			x = x * 10 + 1;
		}
		std::cout << count<<std::endl;
	}
}
