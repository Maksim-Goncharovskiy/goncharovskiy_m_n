#include <iostream>
#include <string>
int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		int n = 0;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		int count_B = 0;
		int count_R = 0;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != 'W') {
				if (s[i] == 'B') {
					count_B += 1;
				}
				else if (s[i] == 'R') {
					count_R += 1;
				}
			}
			else {
				if (count_B == 0 && count_R > 0) {
					ans = false;
					break;
				}
				else if (count_B > 0 && count_R == 0) {
					ans = false;
					break;
				}
				count_B = 0;
				count_R = 0;
			}
		}
		if (count_B + count_R > 0) {
			if (count_B > 0 && count_R == 0) {
				std::cout << "No" << std::endl;
			}
			else if (count_R > 0 && count_B == 0) {
				std::cout << "No" << std::endl;
			}
			else {
				std::cout << "Yes" << std::endl;
			}
		}
		else if (ans) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
	}
	
}
