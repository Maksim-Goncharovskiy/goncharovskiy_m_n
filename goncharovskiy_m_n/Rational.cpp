#include <iostream>
#include <cmath>
class Rational {
private:
	int numerator_ = 0;
	int denominator_ = 1;

	void reduction() {
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

public:
	// Конструкторы, деструктор
	Rational(){
		std::cout << "Constructor has worked -> " << this << std::endl;
	}

	Rational(int num, int denom) {
		if (denom <= 0) {
			throw "Incorrect input data";
		}
		else {
			numerator_ = num;
			denominator_ = denom;
			reduction();
			std::cout << "Constructor has worked -> " << this << std::endl;
		}
	}

	Rational(const Rational &other){} //конструктор копирования

	~Rational(){
		std::cout << "Destructor has worked -> " << this << std::endl;
	} 

	// Получение и запись числителя и знаменателя
	int get_num() {
		return numerator_;
	}
	int get_denom() {
		return denominator_;
	}

	void set_num(int new_num) {
		numerator_ = new_num;
		reduction();
	}
	void set_denom(int new_denom) {
		denominator_ = new_denom;
		reduction();
	}

	Rational& operator+=(Rational other);
	Rational& operator+=(int other);
	Rational& operator-=(Rational other);
	Rational& operator-=(int other);
	Rational& operator*=(const Rational& other);
	Rational& operator*=(const int& other);
	Rational& operator/=(const Rational& other);
	Rational& operator/=(const int& other);

};


//Определения методов арифметики
Rational& Rational::operator+=(Rational other) {
	int first = this->denominator_;
	int second = other.denominator_;
	this->denominator_ *= second;
	this->numerator_ *= second;
	other.denominator_ *= first;
	other.numerator_ *= first;
	this->numerator_ += other.numerator_;
	reduction();
	return *this;
}

Rational& Rational::operator+=(int other) {
	this->numerator_ += other * this->denominator_;
	reduction();
	return *this;
}

Rational& Rational::operator-=(Rational other) {
	int a = other.denominator_;
	int b = this->denominator_;
	this->denominator_ *= a;
	this->numerator_ *= a;
	other.denominator_ *= b;
	other.numerator_ *= b;
	this->numerator_ -= other.numerator_;
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


int main() {
	Rational a(5, 2);
	Rational b(4, 1);
	a /= 5;
	std::cout << a.get_num() <<'/'<<a.get_denom() << std::endl;
}
