#include <geom/geom.h>
#include <iostream>
#include <cmath>
int main() {
    Rdec2D r_m = { 0, -10 };
    Rdec2D r_c = { 10, 0 };
    Rdec2D v_m = { 0, -100 };
    Rdec2D v_c;
    double radius = 1;

    double prev_distance; //Расстояние между котом и мышью. Будем считать за первоначальное расстояние, а потом смотреть как оно будет меняться
    prev_distance = Norm(r_m - r_c);
    double t = 0.01;

    r_m = r_m + v_m * t;
    r_c = r_c + v_c * t;
    v_c = (r_m - r_c) * (1 / Norm(r_m - r_c));

    while ((r_m.y < 0) && (Norm(r_m - r_c) > radius)) {
        if (prev_distance < Norm(r_m - r_c) && v_m.y < 0) { //случай когда мышь убегает
            break;
        }
        prev_distance = Norm(r_m - r_c);
        r_m = r_m + v_m * t;
        r_c = r_c + v_c * t;
        v_c = (r_m - r_c) * (1 / Norm(r_m - r_c));
    }
    if (r_m.y >= 0) {
        std::cout << "Mouse will be alive"<< std::endl;
    }
    else if (Norm(r_m - r_c) <= radius) {
        std::cout << "Cat had a nice dinner"<< std::endl;
    }
    else if (prev_distance <= Norm(r_m - r_c)) {
        std::cout << "Mouse really fast" << std::endl;
    }
}
