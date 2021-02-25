#include <iostream>
#include <string>
#include <vector>

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

bool inverse(int number, int mod, int &answer) {
	if (gcd(number, mod) == 1) {
		int x = 0;
		int remainder = 0;
		while (remainder != 1) {
			x++;
			remainder = (number * x) % mod;
		}
		answer = x;
		return true;
	}
	else {
		return false;
	}
}

int eulerphi(int number) {
	int count = 0;
	for (int i = 1; i <= number; i++) {
		if (gcd(i, number) == 1) {
			count++;
		}
	}
	return count;
}

vector<int> divisor(int number) {
	vector<int> divset;
	for (int i = 1; i <= number; i++) {
		if (number % i == 0) {
			divset.push_back(i);
		}
	}
	return divset;
}

// menu function
void menu() {
	cout << "Enter the corresponding number to select an option :";
	cout << "\n\n------------Menu------------";
	cout << "\n\n1.   GCD (Pair)";
	cout << "\n2.   Inverse of Congruence";
	cout << "\n3.   Euler Phi";
	cout << "\n4.   Divisors";
	cout << "\n\n5.   Exit\n\n";
}

int main() {
	int choice;
	bool exit = false;
	int numberIn;
	int numberIn2;
	int inv;
	vector<int> divisors;

    while (exit == false) {
        system("cls"); // clear screen
        menu(); // print out the menu
        cout << "Enter your option here : "; // prompt user for the choice number
        cin >> choice; // fish the choice number into a variable
        cout << endl;
        // input validation in case the user enters a non-integer
        if (cin.fail()) {
            cout << "Invalid option, try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            system("pause");
        }
        else {
            switch (choice) {
            case 1:
				cout << "Please enter the first number:" << endl;
				cin >> numberIn;
				cout << endl;
				cout << "Please enter the second number:" << endl;
				cin >> numberIn2;
				cout << endl;
				cout << "The GCD of the two numbers entered are:" << endl;
				cout << gcd(numberIn, numberIn2) << endl;
				cout << endl;
				system("pause"); // system pause
                break;
			case 2:
				cout << "Please enter the first number:" << endl;
				cin >> numberIn;
				cout << endl;
				cout << "Please enter the second number:" << endl;
				cin >> numberIn2;
				cout << endl;
				if (inverse(numberIn, numberIn2, inv) == true) {
					cout << "The inverse of the congruence equation is:" << endl;
					cout << inv << endl;
				}
				else {
					cout << "No inverse found!" << endl;
				}
				cout << endl;
				system("pause"); // system pause
				break;
			case 3:
				cout << "Please enter a number:" << endl;
				cin >> numberIn;
				cout << endl;
				cout << "The Euler Phi of the number is:" << endl;
				cout << eulerphi(numberIn) << endl;
				cout << endl;
				system("pause"); // system pause
				break;
			case 4:
				cout << "Please enter a number:" << endl;
				cin >> numberIn;
				cout << endl;
				cout << "The divisor set of the number are:" << endl;
				divisors = divisor(numberIn);
				for (int i = 0; i < divisors.size(); i++) {
					cout << divisors.at(i);
					if (i < divisors.size() - 1) {
						cout << ", ";
					}
				}
				cout << endl << endl;
				system("pause"); // system pause
				break;
			case 5: // exit
				cout << "Good Bye!" << endl << endl;
				exit = true;
				break;
			default: // input validation in case choice option is < 1 or > 8
				cout << "Invalid option, try again." << endl;
				cout << endl;
				system("pause");
				break;
			}
        }
    }
	cout << "Press any key to close this window . . ." << endl;
	system("pause>nul");
	return 0;
}