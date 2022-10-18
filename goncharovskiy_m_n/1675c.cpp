#include <iostream>
#include <string>
int main() {
	std::string s;
	std::cin >> s;
	int count = 0;
	int ind_1 = -1; // индекс самой правой 1
	int ind_0 = s.size(); // индекс самого левого нуля
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 0) {
			ind_0 = i;
			break;
		}
		if (i == s.size() - 1 && s[i] != '0') {
			ind_0 = s.size() + 1;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			ind_1 = i;
			break;
		}
		if (i == 0 and s[0] != '1') {
			ind_1 = -1;
		}

	}
	std::cout << ind_0 - ind_1 << std::endl;
}
