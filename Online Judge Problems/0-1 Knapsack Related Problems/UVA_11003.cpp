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
ll weight[1005];
ll capacity[1005];
ll dp[1005][6005];
ll knapsack(ll i , ll w) {
    if ( i == 0 ) return 0 ;
    if ( dp[i][w] != -1) return dp[i][w];
    if ( w <= capacity[i]) 
        return dp[i][w] = max(1+knapsack(i-1,w+weight[i]),knapsack(i-1,w));
    else return dp[i][w] = knapsack(i-1,w);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        ll n ;
        scanf("%lld",&n);
        if ( n == 0 ) break ;
        memset(weight,0,sizeof(weight));
        memset(capacity,0,sizeof(capacity));
        memset(dp,-1,sizeof(dp));
        INC(i,1,n) scanf("%lld %lld",&weight[i],&capacity[i]);
        printf("%lld\n",knapsack(n,0));
    }
 
    return 0 ;
}