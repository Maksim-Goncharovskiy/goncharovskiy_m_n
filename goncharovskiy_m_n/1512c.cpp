//Задача A-B палиндром
#include <iostream>
#include <string>
int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++){
		int a = 0, b = 0;
		std::cin >> a >> b;
		int copy_a = a, copy_b = b;
		std::string s;
		std::cin >> s;
		int n = a + b;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				b = b - 1;
			}
			else if (s[j] == '0') {
				a = a - 1;
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				if (s[(n - i - 1) % n] == '?') {
					if (b > 0) {
						s[(n - i - 1) % n] = '1';
						b = b - 1;
					}
				}
			}
			else if (s[i] == '0') {
				if (s[(n - i - 1) % n] == '?') {
					if (a > 0) {
						s[(n - i - 1) % n] = '0';
						a = a - 1;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				if (s[n - i - 1] == '?') {
					if (a >= 2) {
						s[i] = '0';
						s[n - i - 1] = '0';
						a = a - 2;
					}
					else if (b >= 2) {
						s[i] = '1';
						s[n - i - 1] = '1';
						b = b - 2;
					}
					else if (a < 2 && b < 2) {
						if (a == 0 && b == 1) {
							s[i] = '1';
						}
						else if (a == 1 && b == 0) {
							s[i] = '0';
						}
						else{
							s[i] = '1';
							s[n - i - 1] = '0';
							a = a - 1;
							b = b - 1;
						}
					}
				}
 
			}
		}
		int count_a = 0, count_b = 0;
		for (int k = 0; k < n; k++) {
			if (s[k] == '0') {
				count_a = count_a + 1;
				if (count_a > copy_a) {
					std::cout << -1 << std::endl;
					break;
				}
			}
			if (s[k] == '1') {
				count_b = count_b + 1;
				if (count_b > copy_b) {
					std::cout << -1 << std::endl;
					break;
				}
			}
			if (s[k] != s[n - k - 1]) {
				std::cout << -1 << std::endl;
				break;
			}
			if (k == n - 1) {
				std::cout << s << std::endl;
			}
		}
	}
}
