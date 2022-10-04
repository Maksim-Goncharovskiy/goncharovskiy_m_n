//Задача Тернарная Логика
#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int a; std::cin >> a;
	int c; std::cin >> c;
	std::vector <int> A;
	std::vector <int> C;
	std::vector <int> B;
	while (a > 0) {
		A.push_back(a % 3);
		a = a / 3;
	}
	while (c > 0) {
		C.push_back(c % 3);
		c = c / 3;
	}

	if (A.size() < C.size()) {
		while (A.size() < C.size()) {
			A.push_back(0);
		}
	}
	if (A.size() > C.size()) {
		while (A.size() > C.size()) {
			C.push_back(0);
		}
	}

	for (int j = 0; j < A.size(); j++) {
		B.push_back((C[j] - A[j] + 3) % 3);
	}
	int b = 0;
	for (int i = 0; i < B.size(); i++) {
		b = b + B[i] * pow(3, i);
	}
	std::cout << b;
}
