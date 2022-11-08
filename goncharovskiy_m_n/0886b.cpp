#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> A(2*100000 + 1);
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		A[x] = i + 1;
	}
	int minim = 10000000;
	int ans = 0;
	for (int j = 0; j < A.size(); j++) {
		if (A[j] < minim && A[j] != 0) {
			minim = A[j];
			ans = j;
		}
	}
	std::cout << ans;
}
