#pragma once

struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};

struct Rpol2D {
	double r = 0.0;
	double phi = 0.0;
};

Rdec2D ToDec(Rpol2D n);

Rpol2D ToPol(Rdec2D n);

double Norm(Rdec2D n);

Rdec2D operator+(Rdec2D n, Rdec2D m);

Rdec2D operator-(Rdec2D n, Rdec2D m);

Rdec2D operator-(Rdec2D n);

Rdec2D operator*(Rdec2D n, double c);

Rdec2D operator*(double c, Rdec2D n);

Rdec2D operator/(Rdec2D, double c);

Rdec2D operator/(double c, Rdec2D);

bool operator==(Rdec2D n, Rdec2D m);

bool operator!=(Rdec2D n, Rdec2D m);

double Dot(Rdec2D n, Rdec2D m);

void print(Rdec2D n);
