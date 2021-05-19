## Explanation

RELATED PROBLEM : [Codeforces 1447D](https://codeforces.com/contest/1447/problem/D)

Good Variation of a LCS Problem . To solve this Problem We need to make some observation . <br>
Let us take Two strings as an Example <br>
A = abba <br>
B = babab <br>
K = 4 <br>
In This Situation the Maximum answer will be LCS( A(1,3) , B(2,5) ) - 3 - 4 = 5 <br>
See It is not Necessary that a Substring will start from the Index 1 . So we can not just Solve this Problem by using straight forward LCS Table . The Picked Substrings can start from any index and also can end in any index . <br> <br>
So, To solve this We Can use a Flag which will indicate us whether the Substring is still continous or it is broken . If the Flag Value is 0 then The Substring is not Continous and If it is 1 then It is Continous . <br><br>

NOT CONTINOUS SUBSTRING <br><br>

Now What if the Substring is not Continous ?? <br>
if the Substring is not Continous i.e the flag value is 0 then under this condition there can be two situations . Either the Characters are matched or not.<br><br>


if the Indexes of the Current state is same i.e **s1[i] == s2[j]** .Then under this condition we need to pick the best result out of 3 situations .<br><br>

1.dp( i+1 , j+1 , 1 ) + (k-2) . We can start a new substring . As a result we will add (k-2) to the result . Because for every added characters we need to subtract one . We are adding two charactes so we need to subtract two . And we will get K as an addition . Because for every matced characters we will get extra K according to the formula .<br>

We also have a option that we don't have to start a new substring .There can be two situations of this scenerio <br> 
2. dp( i+1 , j , 0) <br>
3. dp( i , j+1 , 0) <br>

if the Index of the Current state is not same i.e s1[i] != s2[j] .Then under this condition we need to pick the best result out of two situations . <br>
We have a option that we don't have to start a new substring . There can be two situations of this scenerio <br> 
1. dp(i+1,j,0) <br>
2. dp(i,j,0) <br><br>

CONTINOUS SUBSTRING <br> <br>

Now What if the Substring is Continous ?? <br>
if the Substring is Continous i.e the flag value is 1 then under this condition there can be two situations . <br>
if the Index of the Current state is same i.e s1[i] == s2[j] .then under this we need to pick the best result out of 4 situations . <br>

1.dp(i+1,j+1,1) + (k-2) . We can Go forward with the Matched Characters . As a result we will add (k-2) to the result . Because for every added characters we need to subtract one . We are adding two charactes so we need to subtract two . And the K we will get as an addition . Because for every matced characters we will get extra K according to the formula <br>
We can also Continue the Substring By not picking the Matched Characters. As a result we need to substract 1 from the answer and will not get additional K because the Characters are not Matched . There can be two situations of this scenerio <br> 
2. dp(i+1,j,1) - 1 <br>
3. dp(i,j,1) - 1 <br>
And the Last option is we just end the substring here that is ,<br>
4. k-2<br>
The Charactes are match that's why K-2 will be the result for current state if we end here .

if the Index of the Current state is not same i.e s1[i] != s2[j] .Then under this condition we need to pick the best result out of 3 situations . <br>
The characters are not matched So now to continue this substring we have two options . As a result we need to substract 1 from the answer and will not get additional K because the Characters are not Matched . There can be two situations of this scenerio <br>  <br> 
1.dp(i+1,j,1) -1 <br>
2.dp(i,j,0)-1 <br>
And the Last option is we just end the substring here that is ,<br>
3. 0 <br>
The Characters are not matched That's why 0 will be answer for this state .


If sizes of string exceed their limit we will return 0 .