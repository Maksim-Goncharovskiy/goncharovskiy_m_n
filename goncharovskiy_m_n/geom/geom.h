#pragma once

struct Rdec2D { 
	double x = 0.0;
	double y = 0.0; 
};

struct Rpd2D {
	double r = 0.0;
	double phi = 0.0;
};

Rdec2D perevod1(Rpd2D n);

Rpd2D perevod2(Rdec2D n);

double lengh(Rdec2D n);

Rdec2D operator+(Rdec2D n, Rdec2D m);

Rdec2D operator-(Rdec2D n, Rdec2D m);

Rdec2D operator*(Rdec2D n, double c);

double dot(Rdec2D n, Rdec2D m);

void print_Rdec(Rdec2D n);
