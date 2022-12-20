// Будем идти с конца каждого слова, проверяя соответственные элементы на равенство. 
// Если попались 2 разных буквы, останавливаемся и смотрим сколько нам нужно отрезать от каждого слова
#include <string>
#include <iostream>
int main() {
	std::string s1;
	std::string s2;

	std::cin >> s1;
	std::cin >> s2;
	
	int minim = 0;

	int ind1 = s1.length();
	int ind2 = s2.length();

	int ans = 0;

	if (ind1 > ind2) {
		minim = ind2;
	}
	else {
		minim = ind1;
	}
	
	ind1 = ind1 - 1;
	ind2 = ind2 - 1;
	for (int i = 0; i < minim; i++) {
		if (s1[ind1] == s2[ind2]) {
			ind1 = ind1 - 1;
			ind2 = ind2 - 1;
		}
		else {
			break;
		}
	}
	ans = ind1 + 1 + ind2 + 1;
	std::cout << ans;
}
