#include <iostream>
#include <cmath>
#include "rational.h"
class Rational {
private:
	int numerator_ = 0;
	int denominator_ = 1;

	void reduction();

	void Check(int denom);
public:
	// Конструкторы, деструктор
	Rational() = default;

	Rational(int num, int denom);

	Rational(const Rational& other);

	~Rational() = default;

	Rational& operator=(const Rational& other);

	// Получение и запись числителя и знаменателя
	int get_num();
	int get_denom();

	void set_num(int new_num);
	void set_denom(int new_denom);

	// Арифметика
	Rational& operator+=(const Rational& other);
	Rational& operator+=(int other);
	Rational& operator-=(const Rational& other);
	Rational& operator-=(int other);
	Rational& operator*=(const Rational& other);
	Rational& operator*=(const int& other);
	Rational& operator/=(const Rational& other);
	Rational& operator/=(const int& other);
	// Инкремент, декремент
	Rational& operator++();
	Rational& operator--();
	Rational& operator++(int value);
	Rational& operator--(int value);

	// Логика
	bool operator==(const Rational& other);
	bool operator!=(const Rational& other);
	bool operator>(const Rational& other);
	bool operator<(const Rational& other);
	bool operator>=(const Rational& other);
	bool operator<=(const Rational& other);

	// Ввод и вывод 
	std::ostream& writeTo(std::ostream& ostrm) const;

	std::istream& readFrom(std::istream& istrm);
};

void Rational::reduction() {
	int min;
	if (abs(numerator_) > abs(denominator_)) {
		min = abs(denominator_);
	}
	else {
		min = abs(numerator_);
	}

	if (numerator_ == 0) {
		denominator_ = 1;
	}
	else {
		for (int i = min; i > 0; --i) {
			if (numerator_ % i == 0 && denominator_ % i == 0) {
				numerator_ /= i;
				denominator_ /= i;
				break;
			}
		}
	}
}

void Rational::Check(int denom) {
	if (denom < 0) {
		throw "Incorrect input data format";
	}
	else if (denom == 0) {
		throw "The denominator cannot be zero";
	}
}

// Определения конструкторов
Rational::Rational(int num, int denom) {
	Check(denom);
	numerator_ = num;
	denominator_ = denom;
	reduction();
	std::cout << "Constructor has worked -> " << this << std::endl;
}
Rational::Rational(const Rational& other) {
	this->numerator_ = other.numerator_;
	this->denominator_ = other.denominator_;
}

//Определения сетеров, гетеров
int Rational::get_num() {
	return numerator_;
}
int Rational::get_denom() {
	return denominator_;
}
void Rational::set_num(int new_num) {
	numerator_ = new_num;
	reduction();
}
void Rational::set_denom(int new_denom) {
	denominator_ = new_denom;
	reduction();
}

//Присваивание
Rational& Rational::operator=(const Rational& other) {
	this->numerator_ = other.numerator_;
	this->denominator_ = other.denominator_;
	return *this;
}

//Определения методов арифметики
Rational& Rational::operator+=(const Rational& other) {
	int first = this->denominator_;
	int second = other.denominator_;
	int third = other.numerator_;
	this->denominator_ *= second;
	this->numerator_ *= second;
	this->numerator_ += third * first;
	reduction();
	return *this;
}

Rational& Rational::operator+=(int other) {
	this->numerator_ += other * this->denominator_;
	reduction();
	return *this;
}

Rational& Rational::operator-=(const Rational& other) {
	int first = this->denominator_;
	int second = other.denominator_;
	int third = other.numerator_;
	this->denominator_ *= second;
	this->numerator_ *= second;
	this->numerator_ -= third * first;
	reduction();
	return *this;
}

Rational& Rational::operator-=(int other) {
	this->numerator_ -= other * this->denominator_;
	reduction();
	return *this;
}

Rational& Rational::operator*=(const Rational& other) {
	this->denominator_ *= other.denominator_;
	this->numerator_ *= other.numerator_;
	reduction();
	return *this;
}

Rational& Rational::operator*=(const int& other) {
	this->numerator_ *= other;
	reduction();
	return *this;
}

Rational& Rational::operator/=(const Rational& other) {
	this->denominator_ *= other.numerator_;
	this->numerator_ *= other.denominator_;
	reduction();
	return *this;
}

Rational& Rational::operator/=(const int& other) {
	this->denominator_ *= other;
	reduction();
	return *this;
}


// Перегрузка арифметических операторов
Rational operator+(const Rational& a, const Rational& b) {
	Rational x = a;
	x += b;
	return x;
}
Rational operator-(const Rational& a, const Rational& b) {
	Rational x = a;
	x -= b;
	return x;
}
Rational operator*(const Rational& a, const Rational& b) {
	Rational x = a;
	x *= b;
	return x;
}
Rational operator/(const Rational& a, const Rational& b) {
	Rational x = a;
	x /= b;
	return x;
}

Rational operator+(const Rational& a, const int& b) {
	Rational x = a;
	x += b;
	return x;
}
Rational operator-(const Rational& a, const int& b) {
	Rational x = a;
	x -= b;
	return x;
}
Rational operator*(const Rational& a, const int& b) {
	Rational x = a;
	x *= b;
	return x;
}
Rational operator/(const Rational& a, const int& b) {
	Rational x = a;
	x /= b;
	return x;
}

//Определение инкремента и декремента
Rational& Rational::operator++() {
	this->numerator_ += this->denominator_;
	reduction();
	return *this;
}
Rational& Rational::operator--() {
	this->numerator_ -= this->denominator_;
	reduction();
	return *this;
}
Rational& Rational::operator++(int value) {
	Rational box(*this);
	this->numerator_ += this->denominator_;
	reduction();
	return box;
}
Rational& Rational::operator--(int value) {
	Rational box(*this);
	this->numerator_ -= this->denominator_;
	reduction();
	return box;
}

//Определения перегруженных логических операторов
bool Rational::operator==(const Rational& other) {
	return ((this->numerator_ == other.numerator_) && (this->denominator_ == other.denominator_));
}
bool Rational::operator!=(const Rational& other) {
	return !(*this == other);
}
bool Rational::operator>(const Rational& other) {
	return ((*this - other).numerator_ > 0);
}
bool Rational::operator<(const Rational& other) {
	return ((*this - other).numerator_ < 0);
}
bool Rational::operator>=(const Rational& other) {
	return ((*this - other).numerator_ >= 0);
}
bool Rational::operator<=(const Rational& other) {
	return ((*this - other).numerator_ <= 0);
}

// Ввод и вывод:
std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << this->numerator_ << "/" << this->denominator_;
	return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm) {
	int num = 6;
	int denom = 6;
	char sep = ' ';
	istrm >> num >> sep >> denom;
	Check(denom);
	if (sep == '/') {
		numerator_ = num;
		denominator_ = denom;
		reduction();
	}
	else {
		throw "Incorrect input data format";
	}
	return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, Rational& x) {
	return x.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& x) {
	return x.readFrom(istrm);
}

int main() {
	try {
		/*Rational first(1, 2);
		std::cout << "first = " << first.get_num() << "/" << first.get_denom() << std::endl;
		first += 1;
		std::cout << "first += 1: " << first.get_num() << "/" << first.get_denom() << std::endl;
		first *= 2;
		std::cout << "first *= 2: " << first.get_num() << "/" << first.get_denom() << std::endl;
		first /= 3;
		std::cout << "first /= 3: " << first.get_num() << "/" << first.get_denom() << std::endl;
		Rational second(5, 15);
		std::cout << "second: " << second.get_num() << "/" << second.get_denom() << std::endl;
		first += second;
		std::cout << "first += second: " << first.get_num() << "/" << first.get_denom() << std::endl;
		Rational third = first + second;
		std::cout << "first = " << first.get_num() << "/" << first.get_denom() << std::endl;
		std::cout << "second = " << second.get_num() << "/" << second.get_denom() << std::endl;
		std::cout << "first + second = " << third.get_num() << "/" << third.get_denom() << std::endl;
		third = first - second;
		std::cout << "first - second = " << third.get_num() << "/" << third.get_denom() << std::endl;
		third = first * second;
		std::cout << "first * second = " << third.get_num() << "/" << third.get_denom() << std::endl;
		third = first / second;
		std::cout << "first / second = " << third.get_num() << "/" << third.get_denom() << std::endl;*/

		Rational first;
		
		std::cin >> first;
		std::cout << first << std::endl;
	}
	catch (const char* err) {
		std::cout << err;
	}
}
