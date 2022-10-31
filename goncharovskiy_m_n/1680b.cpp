#include <iostream>
#include <array>
#include <string>
 
int main()
{
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		int n, m;
		std::cin >> n >> m;
		int max_high = 6;
		int max_left = 6;
		int x = 6;
		int y = 6;
		for (int i = 0; i < n; i++) {
			std::string s;
			std::cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'R') {
					if (j < max_left) {
						max_left = j;
					}
					if (i < max_high) {
						max_high = i;
					}
					if (i + j < x + y) {
						x = i;
						y = j;
					}
				}
			}
		}
		if (x > max_high or y > max_left) {
			std::cout << "No"<<std::endl;
		}
		else {
			std::cout << "Yes"<<std::endl;
		}
	}
	
}
