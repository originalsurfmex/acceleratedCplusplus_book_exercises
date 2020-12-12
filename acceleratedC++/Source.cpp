#include <iostream>
#include <string>

using std::cout;	using std::cin;
using std::endl;	using std::string;

int main() {
	// input name
	cout << "input name: ";

	// read name
	string name;
	cin >> name;
	cout << endl;
	const string greeting = "this is" + name + "stret";

	// size
	cout << name + ", how much spacing around the name? (whole number):";
	int spacing;
	cin >> spacing;

	// blank padding surrounding the greeting (lines and/or spaces)
	const int pad = spacing;

	// rows and columns to write
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	// blankyblank
	cout << endl;

	// write rows, procedurally, with conditions
	// invariant: 'r' rows written have been written so far == true
	int rowchanger = 0;
	int greetrow = 0;
	for (int r = 0; r != rows + rowchanger; ++r) {
		string::size_type c = 0;
		// invariant: 'c' characters written so far in current row == true
		while (c != cols) {
			// find beginning of greeting message location and write it
			if (r == pad + 1 + greetrow && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				// find borders and write them
				if (r == 0 || r == rows + rowchanger - 1 || c == 0 || c == cols - 1) {
					cout << "*";
				}
				else {
					cout << " ";
				}
				++c;
			}
		}
		cout << endl;
	}

	int nrows = 20;
	int ncols = 20;
	for (int r = 0; r != nrows; ++r) {
		string::size_type c = 0;
		while (c != ncols) {
			cout << "*";
			++c;
		}
		cout << endl;
	}

	nrows = 20;
	ncols = 41; //must be odd and at least double qty of rows
	int ncolcntr = ncols / 2;
	for (int r = 0; r != nrows; ++r) {
		string::size_type c = 0;
		for (int c = 0; c != ncols; ++c) {
			if (c == ncolcntr + r || c == ncolcntr - r) {
				cout << "*";
			}
			else if (r == nrows - 1 && c != 0 && c != ncols -1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	double PI = 3.14159;
	nrows = 31;
	ncols = 41; 
	int centerX = ncols / 2;
	int centerY = nrows / 2;
	int radius = 10;
	int dx;		// distance in rows from center Y
	int dy;		// distance in columns from center X
	int d;		// pythagorean equation of SQRT(X^2 + Y^2) = radius (distance)
	for (int r = 0; r != nrows; ++r) {
		for (int c = 0; c != ncols; ++c) {
			// distance equations get evaulated each time 
			// the loop hits the next "grid" "cell"
			dx = r - centerY;
			dy = c - centerX;
			d = std::sqrt(dx * dx + dy * dy);
			// border
			if (c == 0 || c == ncols - 1 || r == 0 || r == nrows - 1) {
				cout << "*";
			}
			// center
			else if (r == centerY && c == centerX) {
				cout << "X";
			}
			// circle
			else if (d == radius) {
				cout << "0";
			}
			// spaces (otherwise everything bunches up against each other)
			else {
				cout << " ";
			}
		}
	cout << endl;
	}
return 0;
}