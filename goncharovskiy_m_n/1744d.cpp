//Делимость на 2^n. Полное решение.
#include <iostream>
#include <vector>
int count_2(int x) {
	int count = 0;
	while (x % 2 == 0) {
		count = count + 1;
		x = x / 2;
	}
	return count;
}

int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		int n = 0;
		std::cin >> n;
		int total_count = 0; //количество двоек в произведении
		for (int i = 0; i < n; i++) {
			int a = 0;
			std::cin >> a;
			total_count = total_count + count_2(a);
		}
		int maxim = 0;
		int j = 1;
		while (j <= n) {
			if (j * 2 <= n) {
				maxim = maxim + 1;
			}
			j = j * 2;
		}
		std::vector <int> A;
		for (int j = 0; j <= maxim; j++) {
			A.push_back(0);
		}
		for (int j = 1; j <= n; j++) {
			int x = count_2(j);
			A[x] = A[x] + 1;
		}
		int ind = maxim;
		int ans = 0;
		while (total_count < n) {
			if (A[ind] > 0) {
				total_count = total_count + ind;
				A[ind] = A[ind] - 1;
				ans = ans + 1;
			}
			else if (ind == 0 && A[0] == 0) {
				ans = -1;
				break;
			}
			else {
				ind = ind - 1;
			}
		}
		std::cout << ans<<std::endl;
	}
}
