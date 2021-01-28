#include <iostream>
using namespace std;

class longint {
public:
	bool arr[256];

	bool operator == (const longint& ref) const {
		return arr == ref.arr;
	}

	bool operator > (const longint& ref) const {
		for (int i = 0; i < 256; i++) {
			if (arr[i] && !ref.arr[i])
				return true;
			if (ref.arr[i] && !arr[i])
				return false;
		}
		return false;
	}

	bool operator < (const longint& ref) const {
		for (int i = 0; i < 256; i++) {
			if (!arr[i] && ref.arr[i])
				return true;
			if (!ref.arr[i] && arr[i])
				return false;
		}
		return false;
	}

	longint operator + (const longint& ref) const {
		bool sum[257];

		bool XOR = 0;
		bool carry = 0;
		for (int i = 255; i >= 0; i--) {
			XOR = arr[i] ^ ref.arr[i];
			sum[i + 1] = XOR ^ carry;
			carry = (arr[i] & ref.arr[i]) | (XOR & carry);
		}
		sum[0] = carry;
	}

	longint operator - (const longint& ref) const {

	}

	longint operator * (const longint& ref) const {

	}

	longint operator % (const longint& ref) const {
		if (arr == ref.arr)
			return longint();
		longint b = *this;
		while (b > ref) {
			longint q;
			while (q < (b / 2))
				q = q * 2;
			b = b - q;
		}
		return b;
	}

	longint pow(const longint& ref) {

	}

	string toHexadecimal() {

	}

	longint(string hexadecimal) {

	}

	longint() {
		for (auto &i : arr)
			i = 1;
	}
};

class point {
public:
	longint x;
	longint y;

	bool operator == (const point& ref) const {
		return x == ref.x && y == ref.y;
	}
	
	point negative() {

	}

	point(longint X, longint Y) {
		x = X;
		y = Y;
	}
	point() = default;
};

point add(point& P, point& Q, longint &p) {
	longint lambda;
	if (P.x == longint())
		return Q;
	if (Q.x == longint())
		return P;
	if (Q.x == P.x) {
		if (Q.y == P.y)
			lambda = 3 * P.x * P.x * ((Q.x - P.x) ^ p - 2);
		else if (Q.y == (p - P.y))
			return point();
		else
			lambda = (Q.y - P.y) * ((Q.x - P.x) ^ p - 2);
		longint x = (lambda * lambda - (P.x + Q.x)) % p;
		return point(x, (lambda * (P.x - x) - P.y) % p);
	}
}

point multiply(longint &scalar, point P, longint &p) {
	point q;
	for (auto i = 255; i >= 0; i--) {
		if (scalar.arr[i])
			q = add(P, q, p);
		P = add(P, P, p);
	}
	return q;
}

void main()
{
	//prime charcateristic
	const longint p = longint("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F");

	//base point
	const point(longint("79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798"),
		longint("483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8"));

	//order of base point; n* G = O;
	const longint n = longint("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141");

    std::cout << "Hello World!\n";
}