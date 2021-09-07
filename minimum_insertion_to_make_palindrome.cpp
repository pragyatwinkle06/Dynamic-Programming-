// A Dynamic Programming based program to find
// minimum number insertions needed to make a
// string palindrome


/*    Minimum insertions to form a palindrome | DP-28

Given a string str, the task is to find the minimum number of characters to be inserted to convert it to palindrome.

Before we go further, let us understand with few examples: 

ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd
abcda: Number of insertions required is 2 i.e. adcbcda which is same as number of insertions in the substring bcd(Why?).
abcde: Number of insertions required is 4 i.e. edcbabcde   */
#include <bits/stdc++.h>
using namespace std;


// A DP function to find minimum
// number of insertions
int findMinInsertionsDP(char str[], int n)
{
	// Create a table of size n*n. table[i][j]
	// will store minimum number of insertions
	// needed to convert str[i..j] to a palindrome.
	int table[n][n], l, h, gap;

	// Initialize all table entries as 0
	memset(table, 0, sizeof(table));

	// Fill the table
	for (gap = 1; gap < n; ++gap)
		for (l = 0, h = gap; h < n; ++l, ++h)
			table[l][h] = (str[l] == str[h])?
						table[l + 1][h - 1] :
						(min(table[l][h - 1],
							table[l + 1][h]) + 1);

	// Return minimum number of insertions
	// for str[0..n-1]
	return table[0][n - 1];
}

// Driver Code
int main()
{
	char str[] = "geeks";
	cout << findMinInsertionsDP(str, strlen(str));
	return 0;
}


