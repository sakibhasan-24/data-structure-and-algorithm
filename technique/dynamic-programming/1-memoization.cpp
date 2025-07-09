//  Dynamic Programming solves each subproblem once and stores the result.



/* 
----------------MEMOIZATION------------------
if we solve something once, we write down the answer so we never solve it again.

we use an array (or sometimes a map) to store those answers

Chocolates = [6, 10, 12, 7, 9]

Index:       0   1   2   3   4
             6  10  12   7   9
Chocolates at index 0, 2, 4 → 6 + 12 + 9 = 27 ✅

Or index 1, 3 → 10 + 7 = 17 ❌

*/

#include<iostream>
#include<vector>
using namespace std;
int helper(int n,vector<int>&seen){
    if(n<=1) return n;

    if(seen[n]!=-1) return seen[n];
    return seen[n]=helper(n-1,seen)+helper(n-2,seen);
  }
    int fib(int n) {
        vector<int>seen(n+1,-1);
       return helper(n,seen);
    
}

int main()

{
    
}