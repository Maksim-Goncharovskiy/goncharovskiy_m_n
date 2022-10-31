#include <iostream>
#include <array>
#include <string>

int main()
{
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		int n, k;
		std::cin >> n >> k ;
		std::string s;
		std::cin >> s;
		int counter = 0;
		for (int i = 0; i < k; i++) {
			if (s[i] == 'W') {
				counter += 1;
			}
		}
		int minim = counter;
		for (int j = k; j < n; j++) {
			if (s[j] == 'W') {
				counter += 1;
			}
			if (s[j - k] == 'W') {
				counter = counter - 1;
			}
			if (counter < minim) {
				minim = counter;
			}
		}
		std::cout << minim << std::endl;
	}
}
