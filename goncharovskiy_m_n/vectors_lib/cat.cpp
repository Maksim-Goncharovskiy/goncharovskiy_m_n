#include "vectors.h"
#include <iostream>
#include <cmath>
int main() {
  Rdec2D r_c = {5, 0};
	Rdec2D r_m = { -1, -8 };
	Rdec2D v_m = { 0, -100 };
	Rdec2D v_c = (r_m - r_c) * (5 / lengh(r_m - r_c));
	
	double Radius = 2;
	std::string ans;
	print_Rdec(v_c);
	
	while ((r_m.y != 0) && (pow(r_m.x - r_c.x, 2) + pow(r_m.y - r_c.y, 2)) > pow(Radius, 2)) {
		r_m = r_m + v_m;
		r_c = r_c + v_c;
		Rdec2D v_c = (r_m - r_c) * (1 / lengh(r_m - r_c));
		if (r_m.y == 0) {
			ans = "Mouse will be alive";
		}
		else if ((pow(r_m.x - r_c.x, 2) + pow(r_m.y - r_c.y, 2)) <= pow(Radius, 2)) {
			ans = "Cat had a nice dinner";
		}
	}
	if (ans == "") {
		ans = "Mouse really fast";
	}
	std::cout << ans;
}
