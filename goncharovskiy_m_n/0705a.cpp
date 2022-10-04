//Задача - Халк
#include <iostream>
int main() {
	int n;
	std::cin >> n;
	int i = 1;
	for (i; i <= n; i++) {
		if (i == n && i % 2 == 0) {
			std::cout << "I love it";
		}
		else if (i == n && i % 2 != 0) {
			std::cout << "I hate it";
		}
		
		else if (i % 2 == 0) {
			std::cout << "I love that ";
		}
		else {
			std::cout << "I hate that ";
		}
	}
}
