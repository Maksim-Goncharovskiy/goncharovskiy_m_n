#include<iostream>
 
int main() {
	using namespace std;
	int t = 0, i = 0;
	int a, b, c;
	cin >> t;
	int ans1, ans2;
	for (i; i < t; i++) {
		cin >> a >> b >> c;
		ans1 = a;
		ans2 = abs(b - c) + c;
		if (ans1 > ans2) {
			cout << 2 << endl;
		}
		else if(ans1 == ans2) {
			cout << 3 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
}
