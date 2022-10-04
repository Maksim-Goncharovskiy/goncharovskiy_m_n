//Уравнивание подарков
#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		long long n = 0;
		long long count = 0;
		std::cin >> n;
		unsigned long long minim_a = 1000000000000000;
		unsigned long long minim_b = 1000000000000000;
		std::vector <long long> A;
		std::vector <long long> B;
		for (int k = 0; k < n; k++) {
			int x = 0;
			std::cin >> x;
			if (x < minim_a) {
				minim_a = x;
			}
			A.push_back(x);
		}
		for (int k = 0; k < n; k++) {
			int x = 0;
			std::cin >> x;
			if (x < minim_b) {
				minim_b = x;
			}
			B.push_back(x);
		}
		long long j = 0;
		while (j < n) {
			if (A[j] > minim_a && B[j] > minim_b) {
				if (A[j] - minim_a < B[j] - minim_b) {
					count = count + A[j] - minim_a;
					count = count + B[j] - minim_b - A[j] + minim_a;
				}
				else {
					count = count + B[j] - minim_b;
					count = count + A[j] - minim_a - B[j] + minim_b;
				}
			}
			else if (A[j] > minim_a && B[j] == minim_b) {
				count = count + A[j] - minim_a;
			}
			else if (A[j] == minim_a && B[j] > minim_b) {
				count = count + B[j] - minim_b;
			}
			j = j + 1;
		}
		std::cout << count << std::endl;
		
	}
}
