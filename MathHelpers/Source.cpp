#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	int remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

string inverse(int number, int mod) {
	if (gcd(number, mod) == 1) {
		int x = 0;
		int remainder = 0;
		while (remainder != 1) {
			x++;
			remainder = (number * x) % mod;
		}
		return to_string(x);
	}
	else {
		return "no inverse found";
	}
}

int main() {
	cout << inverse(3, 5);
}