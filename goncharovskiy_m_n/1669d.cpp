#include <iostream>
#include <string>
int main() {
	int n = 0;
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
			else if ()
		}
	}
}
