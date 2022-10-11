#include <iostream>
#include <vector>
int main() {
	std::vector <int> moves_i;
	std::vector <int> moves_j;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			char x;
			std::cin >> x;
			if (x == '#') {
				moves_i.push_back(i);
				moves_j.push_back(j);
			}
		}
	}
	for (int k = 0; k < moves_i.size(); k++) {
		std::cout << moves_i[k] << ' ' << moves_j[k] << std::endl;
	}
}
