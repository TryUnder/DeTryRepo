/*
Przyklad a = x^y = 2^(y*log.2.x)
*/

#include <iostream>

double Func(const double y, const double x) {
	double result = 0.0f;
	__asm {
		fld y;					y
		fld x;					x, y
		fyl2x;					y* log.2.x
		f2xm1;					2 ^ (y * log.2.x) - 1
		fld1;					1, 2 * (y * log.2.x) - 1
		fadd;					a
		fstp result;
	}
}

int main() {
	std::cout << " x^y " << Func(0.9f, 0.6f) << std::endl;
	//https://www.google.com/search?q=2%5E%280.9*log2+0.6%29&sxsrf=ALiCzsal5LKzx7ps-NmOrL_JpFJxBtZ13A%3A1654339111477&ei=JzabYtHgHImxrgS_krUo&ved=0ahUKEwiRkM-4zZP4AhWJmIsKHT9JDQUQ4dUDCA4&uact=5&oq=2%5E%280.9*log2+0.6%29&gs_lcp=Cgdnd3Mtd2l6EANKBAhBGAFKBAhGGABQ6wxY_yBg7iJoAXAAeACAAZEBiAGnA5IBAzMuMZgBAKABAcABAQ&sclient=gws-wiz
	// x > 0
    // wykladnik f2xm1 <-1,1>
}
