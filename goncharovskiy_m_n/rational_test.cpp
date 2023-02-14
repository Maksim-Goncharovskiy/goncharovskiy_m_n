#include <rational_lib/rational.h>
#include <iostream>
int main() {
	try {
		std::cout << "Starting of the test..." << std::endl;
		std::cout << "Checking of +=, -=, *=, /=" << std::endl;
		Rational ex(3, 7);
		std::cout << "Our var = " << ex << std::endl;
		ex += 2;
		std::cout << "Var after += 2: " << ex << std::endl;
		ex -= 2;
		std::cout << "Var after -= 2: " << ex << std::endl;
		ex *= 3;
		std::cout << "Var after *= 3: " << ex << std::endl;
		ex /= 3;
		std::cout << "Var after /= 3: " << ex << std::endl;
		std::cout << std::endl;


		std::cout << "Checking of +, -, *, / with numbers" << std::endl;
		Rational first(1, 2);
		std::cout << first<< " + " << 1 << " = " << first + 1 << std::endl;
		std::cout << -1 << " + " << first << " = " << -1 + first << std::endl;
		std::cout << first << " - " << 1 << " = " << first - 1 << std::endl;
		std::cout << 1 << " - " << first << " = " << 1 - first << std::endl;
		std::cout << first << " * " << 3 << " = " << first * 3 << std::endl;
		std::cout << 3 << " * " << first << " = " << 3 * first << std::endl;
		std::cout << first << " / " << 5 << " = " << first / 5 << std::endl;
		std::cout << first << " / " << -5 << " = " << first / -5 << std::endl;
		std::cout << 5 << " / " << first << " = " << 5 / first << std::endl;
		std::cout << -5 << " / " << first << " = " << -5 / first << std::endl;
		std::cout << std::endl;


		Rational second(-3, 10);
		std::cout << "Checking of + , -, *, / with Rational" << second << std::endl;
		std::cout << first << " + " << second << " = " << first + second << std::endl;
		std::cout << first << " - " << second << " = " << first - second << std::endl;
		std::cout << first << " * " << second << " = " << first * second << std::endl;
		std::cout << first << " / " << second << " = " << first / second << std::endl;
		std::cout << std::endl;

		std::cout << "Checking of ==, !=, >, >=, <= " << std::endl;
		std::cout << first <<" == "<< second<<": " << (first == second) << std::endl;
		std::cout << first << " != " << second << ": " << (first != second) << std::endl;
		std::cout << first << " > " << second << ": " << (first > second) << std::endl;
		std::cout << first << " < " << second << ": " << (first < second) << std::endl;
		std::cout << first << " >= " << second << ": " << (first >= second) << std::endl;
		std::cout << first << " <= " << second << ": " << (first <= second) << std::endl;
		std::cout << std::endl;

		std::cout << "Checking ++, --" << std::endl;
		Rational third(4, 9);
		std::cout << third << "++" << ": " << third++ << std::endl;
		std::cout << third << "--" << ": " << third-- << std::endl;
		std::cout << "++" << third << ": " << ++third << std::endl;
		std::cout << "--" << third << ": " << --third << std::endl;
		std::cout << std::endl;


		std::cout << "Checking input/output" << std::endl;
		std::cout << "Write your rational number: " << std::endl;
		Rational in_put;
		std::cin >> in_put;
		std::cout << "Output your number: " << in_put << std::endl;
		
	}
	catch (char* err) {
		std::cout << err;
	}
}
