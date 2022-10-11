#Задача - Подарки
#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> answer;
	for (int i = 0; i < n; i++) {
		answer.push_back(0);
	}

	for (int i = 1; i <= n; i++) {
		int x = 0;
		std::cin >> x;
		answer[x - 1] = i;
	}
	for (int j = 0; j < n; j++) {
		std::cout << answer[j] << ' ';
	}
}
