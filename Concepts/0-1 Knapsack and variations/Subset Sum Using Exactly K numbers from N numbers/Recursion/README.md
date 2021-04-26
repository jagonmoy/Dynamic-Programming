## Explanation

Here , An array of N elements is Given . You will need to Use Exactly K numbers to make the Sum equal to some given sum S .

It's a modification of Subset Sum Problem . We know that , For Subset Sum problem we need to use 2 dimensional DP array that's why the overall Complexity was O(N^2) but for this Problem we will have to use 3 dimensial array . Additional Dimension is for the Additional Condition of K elements .

Well , For General Subset Sum Problem , the Base condition for the Recursion Was,<br>
    if ( currentCapacity == 0 ) return 1 <br> 
    else if ( CurrentIndex == 0) return 0 <br>

But for this Modication Problem ,the Base condition for Recursion will be , <br>
    if ( CurrentCapacity == 0 && CurrentK == 0) return 1 <br>
    else if ( CurrentCapacity == 0 && CurrentK != 0) return 0 <br>
    else if ( CurrentCapacity != 0 && CurrentK == 0) return 0 <br>
    else if ( CurrentIndex == 0) return 0 <br> 
    else if ( CurrentIndex < CurrentK) return 0 ; <br>

Now For Recursion with Recursion With DP Problem we will store the value in DP array 


if ( CurrentCapacity == 0 && CurrentK == 0) return dp[CurrentIndex][CurrentCapacity][CurrentK] = 1 <br>
else if ( CurrentCapacity == 0 && CurrentK != 0) return dp[CurrentIndex][CurrentCapacity][CurrentK] = 0  <br>
else if ( CurrentCapacity != 0 && CurrentK == 0) return dp[CurrentIndex][CurrentCapacity][CurrentK] = 0 <br>
else if ( CurrentIndex == 0) return dp[CurrentIndex][CurrentCapacity][CurrentK] = 0 <br>
else if ( CurrentIndex < CurrentK) return dp[CurrentIndex][CurrentCapacity][CurrentK] = 0 ; <br>

For Iterative Version , We will Exactly Use this Base condition to Initialize the DP array .

Now the Main Part of the Recursion  will be , <br>
    if ( v[CurrentIndex] <= CurrentCapacity ) <br>
        return  func(CurrentIndex-1,CurrentCapacity - v[CurrentIndex],CurrentK-1) + func(CurrentIndex-1,CurrentCapacity,CurrentK)  

Recursion with DP , Iterative Version for both Method the Conditions will be same