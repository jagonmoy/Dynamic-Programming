## Explanation

Very Similar to the LCS Problem . We need to modify a few things for this Question . <br>
In the Parent LCS Problem First we calculate the DP table where each state contain the Length of the LCS up to that state . Then From this DP table we generate the LCS String by traversing Backwards . <br>
But in this Problem we will have to maintain a 2D string array parallely with DP array so that we can track the string up to state (i,j) . Because there will be a stage where we need to pick the Lexicographically Smaller String between the string 
up to (i-1,j) and (i,j-1) . <br>
If you Have a solid Understanding of How LCS works . It will be lot easier to understand the Code .