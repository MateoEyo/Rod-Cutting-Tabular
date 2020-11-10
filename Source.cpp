/*
Rod Cutting Problem solved using a tabular/non recursive approach
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Begin the program
int main() {

	// Create size and table to contain lengths, prices, and max revenue of the rod;
	const int SIZE = 11;
	int priceTable[3][SIZE] = { {0,1,2,3,4,5,6,7,8,9,10}, {0,1,5,8,9,10,17,17,20,24,30} };
	int maxRevenue = -1;

	// A rod of length 0 brings in 0 revenue;
	priceTable[2][0] = 0;

	// Iteratively find the highest revenue per length of the rod
	for (size_t i = 1; i < SIZE; i++) {
		maxRevenue = -1;
		for (size_t j = 1; j <= i; j++) {
			maxRevenue = max(maxRevenue, priceTable[1][j] + priceTable[2][i - j]);
		}
		priceTable[2][i] = maxRevenue;
	}

	// Print out results
	cout << left << setw(7) << setfill(' ') << "Index";
	cout << left << setw(7) << setfill(' ') << "Price";
	cout << left << setw(7) << setfill(' ') << "Revenue" << endl;
	for (size_t i = 1; i < SIZE; i++) {
		for (size_t j = 0; j < 3; j++) {
			cout << left << setw(7) << setfill(' ') << priceTable[j][i];
		}
		cout << endl;
	}
}