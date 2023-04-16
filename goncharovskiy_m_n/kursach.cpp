#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Point {
	double x_ = 0;
	double y_ = 0;
	Point(double x, double y) {
		x_ = x;
		y_ = y;
	}
};

enum position {
	in,
	on_1,
	on_2,
	on_3,
	out
};

struct Triangle {
	std::vector<Point*> vertices;
	std::vector<Triangle*> adjacent;

	Triangle(Point* A, Point* B, Point* C) {
		vertices.push_back(A);
		vertices.push_back(B);
		vertices.push_back(C);
	}

	position CheckPoint(Point& new_point) {
		double eps = 0.00000001;
		double first = (vertices[0]->x_ - new_point.x_) * (vertices[1]->y_ - vertices[0]->y_) - 
			(vertices[1]->x_ - vertices[0]->x_) * (vertices[0]->y_ - new_point.y_);

		double second = (vertices[1]->x_ - new_point.x_) * (vertices[2]->y_ - vertices[1]->y_) -
			(vertices[2]->x_ - vertices[1]->x_) * (vertices[1]->y_ - new_point.y_);

		double third = (vertices[2]->x_ - new_point.x_) * (vertices[0]->y_ - vertices[2]->y_) -
			(vertices[0]->x_ - vertices[2]->x_) * (vertices[2]->y_ - new_point.y_);

		if ((abs(first) > eps && abs(second) > eps && abs(third) > eps)&&((first > 0 && second > 0 && third > 0) || ((first < 0 && second < 0 && third < 0)))) {
			return in;
		}
		else if (abs(first) <= eps) {
			return on_1;
		}
		else if (abs(second) <= eps) {
			return on_2;
		}
		else if (abs(third) <= eps) {
			return on_3;
		}
		else {
			return out;
		}
	}

};

int main() {
	int N = 0; // количество точек в триангуляции
	std::cin >> N;
	std::vector<Point> input;
	for (int i = 0; i < N; i++) {
		double x = 0;
		double y = 0;
		std::cin >> x >> y;
		input.push_back(Point(x, y));
	}

	std::vector<Triangle> result;
	result.push_back(Triangle(&input[0], &input[1], &input[2]));

	for (int i = 3; i < N; i++) {
		for (int j = 0; j < result.size(); j++) {
			position new_point = result[j].CheckPoint(input[i]);
			if (new_point == in) {
				Point* A = result[j].vertices[0];
				Point* B = result[j].vertices[1];
				Point* C = result[j].vertices[2];
				//!!! Тут подумать, нужно разбить исходный треугольник на три, но они по отношению друг другу странненькие, пока что хотя бы просто разбить
				result[j] = Triangle(A, B, &input[i]);
				result.push_back(Triangle(B, C, &input[i]));
				result.push_back(Triangle(A, C, &input[i]));
			}
		}
	}
	
	for (int i = 0; i < result.size(); i++) {
		std::cout << i + 1 << ": " << "A(" << result[i].vertices[0]->x_ << ", " << result[i].vertices[0]->y_ << ")" << "     B(" << result[i].vertices[1]->x_ << ", " << result[i].vertices[1]->y_ << ")" << "          C(" << result[i].vertices[2]->x_ << ", " << result[i].vertices[2]->y_ << ")" << std::endl;
	}
}
