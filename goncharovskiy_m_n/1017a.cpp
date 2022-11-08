#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int>A;
	int tomas = 0;
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < 4; j++) {
			int x = 0;
			std::cin >> x;
			s = s + x;
		}
		if (i == 0) {
			tomas = s;
		}
		A.push_back(s);
	}
	sort(A.begin(), A.end());
	for (int k = n - 1; k >= 0; k--) {
		if (A[k] == tomas) {
			std::cout << n - k;
			break;
		}
	}
}
