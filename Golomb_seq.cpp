/* Golomb sequence

In mathematics, the Golomb sequence is a non-decreasing integer sequence where n-th term is equal to number of times n appears in the sequence.
The first few values are 
1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ……
Explanation of few terms: 
Third term is 2, note that three appears 2 times. 
Second term is 2, note that two appears 2 times. 
Fourth term is 3, note that four appears 3 times.
Given a positive integer n. The task is to find the first n terms of Golomb sequence. 
Examples : 
 

Input : n = 4
Output : 1 2 2 3

Input : n = 6
Output : 1 2 2 3 3 4 */
// C++ Program to find first
// n terms of Golomb sequence.
#include <bits/stdc++.h>
using namespace std;

// Print the first n term
// of Golomb Sequence
void printGolomb(int n)
{
	int dp[n + 1];

	// base cases
	dp[1] = 1;
	cout << dp[1] << " ";

	// Finding and printing first
	// n terms of Golomb Sequence.
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1 + dp[i - dp[dp[i - 1]]];
		cout << dp[i] << " ";
	}
}
// Driver Code
int main()
{
	int n = 9;

	printGolomb(n);
	return 0;
}
