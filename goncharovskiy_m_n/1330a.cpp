//Задача Dreamoon и сбор мест 
#include <iostream>
#include <vector>
#include <algorithm> 
int main() {
	int t = 0, n = 0, x = 0;
	std::cin >> t;
	int i = 0;
	for (i; i < t; i++) {
 
		std::cin >> n >> x;
		int j = 0;
		std::vector <int> a(n);
 
		for (j; j < n; j++) {
			std::cin >> a[j];
		}
		sort(a.begin(), a.end());
 
		std::vector <int> jojo(300);
		for (j = 0; j < n; j++) {
			jojo[a[j] - 1] = 1;
		}
		j = 0;
		while (x > 0) {
			if (jojo[j] == 0) {
				x = x - 1;
				jojo[j] = 1;
			}
			j = j + 1;
		}
		bool flag = true;
		int cnt = 0;
		j = 0;
		while (flag) {
			if (jojo[j] == 0) {
				flag = false;
			}
			else {
				cnt = cnt + 1;
				j = j + 1;
			}
		}
		std::cout << cnt << std::endl;
	}
}
