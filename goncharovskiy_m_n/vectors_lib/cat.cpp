#define _USE_MATH_DEFINES
#include "vectors.h"
#include <iostream>
#include <cmath>
#include <iomanip>

int main(Rdec2D r_m, Rdec2D r_c, Rdec2D v_m, Rdec2D v_c, double CatRad, double v0) {
	Rdec2D r_m;
	Rdec2D r_c;
	Rdec2D v_c;
	double radius = 3; 
    
    	double last;
    	last = norm(r_m - r_c);
    	double dt = 0.01;
    	double count_t = 0;
    	
	r_m = r_m + v_m * dt;
    	r_c = r_c + v_c * dt;
    	v_c = (r_m - r_c) * (1 / norm(r_m - r_c)) * v0;
    	count_t += dt;

    	while ((r_m.y < 0) && (norm(r_m - r_c) > radius)) {
        	if (last < norm(r_m - r_c) && v_m.y < 0)
            	break;
       		last = norm(r_m - r_c);
        	count_t += dt;
        	r_m = r_m + v_m * dt;
        	r_c = r_c + v_c * dt;
        	v_c = (r_m - r_c) * (1 / norm(r_m - r_c)) * v0;
    	}
    	if (r_m.y >= 0) {
        	std::cout << "Mouse in Hole in " << count_t << " second\n";
    	}
    	else if (norm(r_m - r_c) <= CatRad) {
        	std::cout << "Cat ate Mouse in " << count_t << " second\n";
    	}
    	else if (last <= norm(r_m - r_c)) {
        	std::cout << "Mouse ran away \n";
    	}
    	return;
}
