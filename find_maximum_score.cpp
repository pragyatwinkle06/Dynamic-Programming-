// CPP program to find maximum score we can get
// by removing elements from either end.

/*  Remove array end element to maximize the sum of product
Difficulty Level : Medium
Last Updated : 23 Jul, 2021
Given an array of N positive integers. We are allowed to remove element from either of the two ends i.e from the left side or right side of the array. Each time we remove an element, score is increased by value of element * (number of element already removed + 1). The task is to find the maximum score that can be obtained by removing all the element.
Examples: 
 

Input : arr[] = { 1, 3, 1, 5, 2 }.
Output : 43
Remove 1 from left side (score = 1*1 = 1)
then remove 2, score = 1 + 2*2 = 5
then remove 3, score = 5 + 3*3 = 14
then remove 1, score = 14 + 1*4 = 18
then remove 5, score = 18 + 5*5 = 43.

Input :  arr[] = { 1, 2 }
Output : 5.    */
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int solve(int dp[][MAX], int a[], int low, int high,int turn)
										
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
