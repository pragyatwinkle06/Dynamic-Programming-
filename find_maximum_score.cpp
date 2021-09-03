// CPP program to find maximum score we can get
// by removing elements from either end.
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int solve(int dp[][MAX], int a[], int low, int high,
										int turn)
{
	// If only one element left.
	if (low == high)
		return a[low] * turn;

	// If already calculated, return the value.
	if (dp[low][high] != 0)
		return dp[low][high];

	// Computing Maximum value when element at
	// index i and index j is to be choosed.
	dp[low][high] = max(a[low] * turn + solve(dp, a,
							low + 1, high, turn + 1),
						a[high] * turn + solve(dp, a,
						low, high - 1, turn + 1));

	return dp[low][high];
}

// Driven Program
int main()
{
	int arr[] = { 1, 3, 1, 5, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int dp[MAX][MAX];
	memset(dp, 0, sizeof(dp));

	cout << solve(dp, arr, 0, n - 1, 1) << endl;
	return 0;
}
