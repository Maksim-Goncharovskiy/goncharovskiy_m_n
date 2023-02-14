#include <iostream>
#include <cmath>
#include "rational.h"
						// Определения методов класса
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



									// Определения внешних перегруженных операторных функций
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


// Ввод и вывод:
std::ostream& operator<<(std::ostream& ostrm, Rational& x) {
	return x.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& x) {
	return x.readFrom(istrm);
}
