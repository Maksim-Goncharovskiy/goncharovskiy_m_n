#define _USE_MATH_DEFINES
#include "vectors.h"
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	Rdec2D r_m = {0, -10};
	Rdec2D r_c = {10, 0};
	Rdec2D r_m = {0, 1};
	Rdec2D v_c;
	double radius = 3; 
    
    	double last;
    	last = lengh(r_m - r_c);
    	double dt = 0.01;
    	double counter = 0;
    	
	r_m = r_m + v_m * dt;
    	r_c = r_c + v_c * dt;
    	v_c = (r_m - r_c) * (1 / lengh(r_m - r_c));
    	counter += dt;

    	while ((r_m.y < 0) && (lengh(r_m - r_c) > radius)) {
        	if (last < lengh(r_m - r_c) && v_m.y < 0)
            	break;
       		last = lengh(r_m - r_c);
        	counter += dt;
        	r_m = r_m + v_m * dt;
        	r_c = r_c + v_c * dt;
        	v_c = (r_m - r_c) * (1 / lengh(r_m - r_c));
    	}
    	if (r_m.y >= 0) {
        	std::cout << "Mouse will be alive"<< counter <<std::endl;
    	}
    	else if (lengh(r_m - r_c) <= radius) {
        	std::cout << "Cat had a nice dinner" << counter << std::endl;
    	}
    	else if (last <= lengh(r_m - r_c)) {
        	std::cout << "Mouse really fast" << std::endl;
    	}
}
