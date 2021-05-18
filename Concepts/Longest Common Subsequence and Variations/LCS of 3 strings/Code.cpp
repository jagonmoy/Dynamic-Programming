#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define PF push_front
#define P push
#define INC(i,a,b) for (ll i = a; i <= b; i++)
#define DEC(i,b,a) for (ll i = b; i >= a ; i--)
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define mod  1000000007
#define eps 1e-9
typedef ostringstream OS ;
typedef stringstream SS ;
typedef long long ll ;
typedef unsigned long long ull;
typedef pair < ll , ll > PLL ;
typedef pair < char,ll > PCL ;
typedef deque < double > DD ;
typedef deque < PCL > DCL ;
typedef deque < ll > DL ;
typedef deque < PLL > DLL ;
typedef deque < char > DC ;
typedef deque < string > DS ;
typedef vector < double > VD;
typedef vector < PCL > VCL ;
typedef vector < ll > VL;
typedef vector < PLL > VLL ;
typedef vector < char > VC ;
typedef vector < string > VS ;
typedef map < ll ,ll > MLL ;
typedef map < char,ll > MCL;
typedef map < ll,char > MLC;
typedef map < string,ll> MSL;
typedef priority_queue < PLL > PQLL ;
typedef priority_queue < ll > PQL ;
typedef stack < ll > SKL ;
typedef stack < PLL > SKLL ;
typedef queue < ll > QL ;
typedef queue < PLL > QLL ;
typedef set < ll > SL ;
typedef set < PLL > SLL ;
typedef set < char > SC ;
typedef vector <VL> graph;
 
string numtostr(ll n) {
     OS str1 ;
     str1 << n ;
     return str1.str();
}
ll strtonum(string s) {
     ll x ;
     SS str1(s);
     str1 >> x ;
     return x ;
}
ll GCD(ll a, ll b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}
ll LCM(ll a , ll b) {
    ll gcd = GCD(a,b);
     return (a/gcd)*b ;
}
string s1,s2,s3 ;
ll dp[55][55][55];
ll lcs(ll i , ll j , ll k) {
    //cout << i << " " << j << " " << k << endl;
    if ( i == 0 || j == 0 || k == 0) return dp[i][j][k] = 0 ;
    if (dp[i][j][k] != -1) return dp[i][j][k] ;
    if ( s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) return dp[i][j][k] = 1+lcs(i-1,j-1,k-1);
    ll maximum = -1 ;
    maximum = max(maximum,lcs(i-1,j-1,k));
    maximum = max(maximum,lcs(i-1,j,k-1));
    maximum = max(maximum,lcs(i,j-1,k-1));
    maximum = max(maximum,lcs(i-1,j,k));
    maximum = max(maximum,lcs(i,j-1,k));
    maximum = max(maximum,lcs(i,j,k-1));
    return dp[i][j][k] = maximum ;
}
 
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
    
   cin >> s1 >> s2 >> s3 ;
   ll len1 = s1.length();
   ll len2 = s2.length();
   ll len3 = s3.length();
   memset(dp,-1,sizeof(dp));
   cout << lcs(len1,len2,len3) << endl;
   return 0 ;
}
