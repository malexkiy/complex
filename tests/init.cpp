#include <complex.h>
#include <catch.hpp>

SCENARIO("complex init", "[init]") {
	Complex c;

	REQUIRE(c.real() == 0);
	REQUIRE(c.imaginary() == 0);
}

SCENARIO("complex init obj", "[init obj]") {
	Complex c(3, 4), d(c);

	REQUIRE(d.real() == 3);
	REQUIRE(d.imaginary() == 4);
}

SCENARIO("complex init param", "[init param]") {
	Complex c(3, 4);

	REQUIRE(c.real() == 3);
	REQUIRE(c.imaginary() == 4);
}

SCENARIO("complex op=", "[op=]") {
	Complex c(3, 4), d;

	d = c;
	REQUIRE(d.real() == 3);
	REQUIRE(d.imaginary() == 4);
}

SCENARIO("complex op==", "[op==]") {
	Complex c(3, 4), d(3, 4);

	REQUIRE(d.real() == 3);
	REQUIRE(d.imaginary() == 4);
	REQUIRE(d == c);
}

SCENARIO("complex op!=", "[op!=]") {
	Complex c(3, 4), d(3, 5), e(5, 4), f(6, 7);

	REQUIRE((c != d) == 1);
	REQUIRE((c != e) == 1);
	REQUIRE((c != f) == 1);
}

SCENARIO("complex op-()", "[op-()]") {
	Complex c(3, 4);

	c = -c;
	REQUIRE(c.real() == -3);
	REQUIRE(c.imaginary() == -4);
}

SCENARIO("complex op*(int)", "[op*(int)]") {
	Complex c(3, 4), d(6, 8);

	c = c * 2;
	REQUIRE(c == d);
}

SCENARIO("complex op*(int)", "[op*(int)]") {
	Complex c(3, 4), d(6, 8);

	d = d / 2;
	REQUIRE(c == d);
}

SCENARIO("complex op*(int)", "[op*(int)]") {
	Complex c(3, 4), d(6, 8);

	c *= 2;
	REQUIRE(c == d);
}

SCENARIO("complex op*(int)", "[op*(int)]") {
	Complex c(3, 4), d(6, 8);

	d /= 2;
	REQUIRE(c == d);
}

SCENARIO("complex op+", "[op+]") {
	Complex c(3, 4), d(6, 8), e(9, 12);

	REQUIRE((c + d) == e);
}

SCENARIO("complex op-", "[op-]") {
	Complex c(9, 12), d(6, 8), e(3, 4);

	REQUIRE((c - d) == e);
}

SCENARIO("complex op*", "[op*]") {
	Complex c(3, 4), d(6, 8), e(-14, 48);

	REQUIRE((c * d) == e);
}

SCENARIO("complex op/", "[op/]") {
	Complex c(3, 4), d(6, 8), e(0.5, 0);

	REQUIRE((c / d) == e);
}

SCENARIO("complex op+=", "[op+=]") {
	Complex c(3, 4), d(6, 8), e(9, 12);

	REQUIRE((c += d) == e);
}

SCENARIO("complex op-=", "[op-=]") {
	Complex c(9, 12), d(6, 8), e(3, 4);

	REQUIRE((c -= d) == e);
}

SCENARIO("complex op*=", "[op*=]") {
	Complex c(3, 4), d(6, 8), e(-14, 48);

	REQUIRE((c *= d) == e);
}

SCENARIO("complex op/", "[op/]") {
	Complex c(3, 4), d(6, 8), e(0.5, 0);

	REQUIRE((c /= d) == e);
}
