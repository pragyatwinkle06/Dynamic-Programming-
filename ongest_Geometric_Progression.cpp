/* Longest Geometric Progression

Given a set of numbers, find the Length of the Longest Geometrix Progression (LLGP) in it. The common ratio of GP must be an integer.
Examples: 

set[] = {5, 7, 10, 15, 20, 29}
output = 3
The longest geometric progression is {5, 10, 20}

set[] = {3, 9, 27, 81}
output = 4 */
// C++ program to find length
// of the longest geometric
// progression in a given set
#include <iostream>
#include <algorithm>
using namespace std;

// Returns length of the
// longest GP subset of set[]
int lenOfLongestGP(int set[], int n)
{
	// Base cases
	if (n < 2)
		return n;
	if (n == 2)
		return (set[1] % set[0] == 0) ? 2 : 1;

	// Let us sort the set first
	sort(set, set+n);

	// An entry L[i][j] in this
	// table stores LLGP with
	// set[i] and set[j] as first
	// two elements of GP
	// and j > i.
	int L[n][n];

	// Initialize result (A single element
	// is always a GP)
	int llgp = 1;

	// Initialize values of last column
	for (int i = 0; i < n - 1; ++i) {
		if (set[n-1] % set[i] == 0)
		{
			L[i][n-1] = 2;
			if (2 > llgp)
			llgp = 2;
		}
		else
		{
			L[i][n-1] = 1;
		}
	}
	L[n-1][n-1] = 1;


	// Consider every element as
	// second element of GP
	for (int j = n - 2; j >= 1; --j)
	{
		// Search for i and k for j
		int i = j - 1, k = j+1;
		while (i>=0 && k <= n-1)
		{
			
			// Two cases when i, j and k don't form
			// a GP.
			if (set[i] * set[k] < set[j]*set[j])
			{
				++k;
			}
			else if (set[i] * set[k] > set[j]*set[j])
			{
				if (set[j] % set[i] == 0)
				{
					L[i][j] = 2;
				}
				else
				{
					L[i][j] = 1;
				}
				--i;
			}


			// i, j and k form GP, LLGP with i and j as
			// first two elements is equal to LLGP with
			// j and k as first two elements plus 1.
			// L[j][k] must have been filled before as
			// we run the loop from right side
			else
			{
				if (set[j] % set[i] == 0)
				{
					L[i][j] = L[j][k] + 1;

					// Update overall LLGP
					if (L[i][j] > llgp)
						llgp = L[i][j];
				} else {
				L[i][j] = 1;
				}


				// Change i and k to fill more L[i][j]
				// values for current j
				--i;
				++k;
			}
		}

		// If the loop was stopped due to k becoming
		// more than n-1, set the remaining entries
		// in column j as 1 or 2 based on divisibility
		// of set[j] by set[i]
		while (i >= 0)
		{
			if (set[j] % set[i] == 0)
			{
				L[i][j] = 2;
				if (2 > llgp)
					llgp = 2;
			}
			else
				L[i][j] = 1;
			--i;
		}
	}

	// Return result
	return llgp;
}

// Driver code
int main()
{
	int set1[] = {1, 3, 9, 27, 81, 243};
	int n1 = sizeof(set1)/sizeof(set1[0]);
	cout << lenOfLongestGP(set1, n1) << "\n";

	int set2[] = {1, 3, 4, 9, 7, 27};
	int n2 = sizeof(set2)/sizeof(set2[0]);
	cout << lenOfLongestGP(set2, n2) << "\n";

	int set3[] = {2, 3, 5, 7, 11, 13};
	int n3 = sizeof(set3)/sizeof(set3[0]);
	cout << lenOfLongestGP(set3, n3) << "\n";

	return 0;
}
