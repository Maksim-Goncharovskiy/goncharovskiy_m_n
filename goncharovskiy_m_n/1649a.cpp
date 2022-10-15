#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++){
		int n = 0;
		std::cin >> n;
		std::vector <int> locations;
		for (int i = 0; i < n; i++) {
			int x = 0;
			std::cin >> x;
			locations.push_back(x);
		}
		int first = 0; //индекс последней единицы перед первым нулём
		int second = 0; //индекс первой единицы после последнего нуля
		int j = 0;
		for (int j = 0; j < n; j++) {
			if (locations[j] == 0) {
				break;
			}
			else {
				first = j;
			}
		}
		for (int k = n - 1; k >= 0; k--) {
			if (locations[k] == 0) {
				break;
			}
			else {
				second = k;
			}
		}
		if (first == n - 1) {
			std::cout << 0 << std::endl;
		}
		else std::cout << second - first << std::endl;
	}
}
