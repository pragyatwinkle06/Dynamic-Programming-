#include <iostream>
#include <numeric>
using namespace std;
 
// Helper function for solving 3 partition problem.
// It returns true if there exist three subsets with a given sum
bool subsetSum(int S[], int n, int a, int b, int c)
{
    // return true if the subset is found
    if (a == 0 && b == 0 && c == 0) {
        return true;
    }
 
    // base case: no items left
    if (n < 0) {
        return false;
    }
 
    // Case 1. The current item becomes part of the first subset
    bool A = false;
    if (a - S[n] >= 0) {
        A = subsetSum(S, n - 1, a - S[n], b, c);
    }
 
    // Case 2. The current item becomes part of the second subset
    bool B = false;
    if (!A && (b - S[n] >= 0)) {
        B = subsetSum(S, n - 1, a, b - S[n], c);
    }
 
    // Case 3. The current item becomes part of the third subset
    bool C = false;
    if ((!A && !B) && (c - S[n] >= 0)) {
        C = subsetSum(S, n - 1, a, b, c - S[n]);
    }
 
    // return true if we get a solution
    return A || B || C;
}
 
// Function for solving the 3–partition problem. It returns true if the given
// set `S[0…n-1]` can be divided into three subsets with an equal sum.
bool partition(int S[], int n)
{
    if (n < 3) {
        return false;
    }
 
    // get the sum of all elements in the set
    int sum = accumulate(S, S + n, 0);
 
    // return true if the sum is divisible by 3 and the set `S` can
    // be divided into three subsets with an equal sum
    return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3);
}
 
int main()
{
    // Input: a set of integers
    int S[] = { 7, 3, 2, 1, 5, 4, 8 };
 
    // total number of items in `S`
    int n = sizeof(S) / sizeof(S[0]);
 
    if (partition(S, n)) {
        cout << "Set can be partitioned";
    }
    else {
        cout << "Set cannot be partitioned";
    }
 
    return 0;
}