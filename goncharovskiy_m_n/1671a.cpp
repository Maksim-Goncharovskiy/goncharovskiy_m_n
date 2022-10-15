#include <string>
#include <iostream>
bool check(int x) {
	for (int i = 0; i < x / 2 + 1; i++) {
		for (int j = 0; j < x / 3 + 1; j++) {
			if (2 * i + 3 * j == x) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		std::string s;
		std::cin >> s;
		std::string ans;
		int cnt = 1; //количество идущих подряд символов
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s[i + 1]) {
				if (check(cnt)) {
					cnt = 1;
				}
				else {
					ans = "NO";
					break;
				}
			}
			else {
				cnt = cnt + 1;
			}
		}

		
		if (ans != "NO") {
			std::cout << "YES" << std::endl;
		}
		
		else {
			std::cout << ans << std::endl;
		}
	}
}
