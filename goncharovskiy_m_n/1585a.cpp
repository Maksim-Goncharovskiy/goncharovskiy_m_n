#Задача - Жизни цветов важны
#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++){
		int n = 0;
		std::cin >> n;
		std::vector <int> check;
		for (int i = 0; i < n; i++) {
			int x = 0;
			std::cin >> x;
			check.push_back(x);
		}

		int k = 1;
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				if (check[j] == 1) {
					k = k + 1;
				}
			}
			else {
				if (check[j] == 1) {
					if (check[j] == check[j - 1]) {
						k = k + 5;
					}
					else {
						k = k + 1;
					}
				}
				else {
					if (check[j - 1] == 0) {
						k = -1;
						break;
					}
				}
			}
		}
		std::cout << k << std::endl;
	}
}
