## Explanation

We will need to modfiy the Shortest Common Supersequence a little bit . <br>
First we will calculate the DP Table for finding LCS for any (i,j) . Where i,j stands for index of two different strings . Now Please Note that , We need the DP table so it is must to find the LCS using Iterative Method . Because , Recursion will not give us the DP table . We will use this dp table in future to develop Way table which will store the number of ways . <br><br>
Now we need to make some observations . <br>
if for any i,j two characters are equal . i.e s[i-1] == s[j-1] then the possible way which will come through ways[i-1][j-1] <br><br>
if the characters are not equal then ?<br>
if dp[i-1][j] > dp[i][j-1] then the possible way will come through ways[i-1][j] <br>
if dp[i][j-1] > dp[i-1][j] then the possible way will come through ways[i][j-1] <br>
if dp[i][j-1] == dp[i-1][j] the the possible way will come thorugh from both ways[i][j-1] and ways[i-1][j] <br><br>
Now What will be the Base Condition ?? <br>
if i or j any index is 0 then we will return 1 . Because between an empty string and a non-empty string there is only one way of making LCS . <br><br>