#include <iostream>
#include <algorithm>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> A;
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		A.push_back(x);
	}
	std::sort(A.begin(), A.end());
	bool flag = true;
	int i = 1;
	for (int j = 0; j < n; j++) {
		if (A[j] >= i) {
			A[j] = A[j] - i;
			i = i + 1;
		}
	}
	std::cout << i - 1;
}
