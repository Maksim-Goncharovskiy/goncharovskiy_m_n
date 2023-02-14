#include <iostream>
class Rational 
{
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


Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);

Rational operator+(const Rational& a, const int& b);
Rational operator-(const Rational& a, const int& b);
Rational operator*(const Rational& a, const int& b);
Rational operator/(const Rational& a, const int& b);

std::ostream& operator<<(std::ostream& ostrm, Rational& x);
std::istream& operator>>(std::istream& istrm, Rational& x);
