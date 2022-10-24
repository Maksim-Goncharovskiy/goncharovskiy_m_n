#include<string>
#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		int n = 0;
		std::string s;
		std::cin >> n;
		std::cin >> s;
		std::string local_s = "";
		std::vector <std::string> A;
		if (s.find('R') >= n && s.find('B') >= n) {
			std::cout << "Yes" << std::endl;
		}
		else{
			for (int i = 0; i < n; i++) {
				char x = s[i];
				if (x != 'W') {
					if (x == 'R') {
						local_s = local_s + "R";
					}
					else {
						local_s = local_s + "B";
					}
				}
				else {
					if (local_s != ""){
						A.push_back(local_s);
						local_s = "";
					}
				}
				if (i == n - 1 && s[i] != 'W') {
					A.push_back(local_s);
				}
			}
			//for (int k = 0; k < A.size(); k++) {
				//std::cout << A[k] << ' ';
			//}
			bool ans = true;
			for (int j = 0; j < A.size(); j++) {
				std::string str = A[j];
				if (str.size() <= 1) {
					ans = false;
					break;
				}
				else if (str.find('R') >= str.size() || str.find('B') >= str.size()) {
					ans = false;
					break;
				}
			}
			if (ans) {
				std::cout << "Yes"<<std::endl;
			}
			else {
				std::cout << "No"<<std::endl;
			}
		}

	}

}
