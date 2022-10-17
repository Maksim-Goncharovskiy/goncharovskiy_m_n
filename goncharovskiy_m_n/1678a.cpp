#include <iostream>
#include <vector>

int count_0(std::vector<int> a) {
	int cnt_0 = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 0) {
			cnt_0 = cnt_0 + 1;
		}
	}
	return cnt_0;
}
bool check(std::vector<int> a) {
	for (int i = 0; i < a.size() - 1; i++) {
		for (int j = i + 1; j < a.size(); j++) {
			if (a[i] == a[j]) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	int t = 0;
	std::cin >> t;
	for (int k = 0; k < t; k++) {
		int n = 0;
		std::cin >> n;
		std::vector <int> a;
		for (int i = 0; i < n; i++) {
			int x = 0;
			std::cin >> x;
			a.push_back(x);
		}
		if (count_0(a) == a.size()) {
			std::cout << 0 << std::endl;
		}
		else if (count_0(a) > 0) {
			std::cout << n - count_0(a) << std::endl;
		}
		else {
			if (check(a)) {
				std::cout << n << std::endl;
			}
			else {
				std::cout << n + 1 << std::endl;
			}
		}
	}
}
