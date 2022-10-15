#include <iostream>
#include <string>
int main() {
	int x = 0, y = 0;
	int x1 = 0, y1 = 0;
	int n = 0;
	int money = 0;
	std::cin >> n;
	std::string S;
	std::cin >> S;
	for (int i = 0; i < n - 1; i++) {
		if (S[i] == 'U') {
			y = y + 1;
			if (x == y) {
				if (S[i + 1] == 'U') {
					if (x1 > y1) {
						money = money + 1;
					}
				}
				else {
					if (y1 > x1) {
						money = money + 1;
					}
				}
			}
		}
		else {
			x = x + 1;
			if (x == y) {
				if (S[i + 1] == 'U') {
					if (x1 > y1) {
						money = money + 1;
					}
				}
				else {
					if (y1 > x1) {
						money = money + 1;
					}
				}
			}
		}
		x1 = x;
		y1 = y;
	}
	std::cout << money;
}
