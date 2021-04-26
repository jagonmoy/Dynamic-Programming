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
ll weight[105];
ll cost[105];
ll dp[105][10205];
ll capacity ;
ll knapsack(ll i , ll w) {
    if ( w > capacity+200 ) return neginf ;
    if ( capacity <= 1800 && w > capacity ) return neginf ;
    if ( i == 0) {
        if ( capacity <= 1800 && w <= capacity) return 0 ;
        else if ( capacity > 2000 && w <= capacity+200) return 0 ;
        else if ( capacity > 1800 && capacity <= 2000 && ((w > 2000 && w <= capacity+200 ) || w <= capacity) ) return 0 ;
        else return neginf ;
    }
    if ( dp[i][w] != -1) return dp[i][w];
    return dp[i][w] = max(cost[i]+knapsack(i-1,w+weight[i]),knapsack(i-1,w));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n ;
    while(scanf("%lld %lld",&capacity,&n) == 2) {
        ll result ;
        memset(dp,-1,sizeof(dp));
        memset(weight,0,sizeof(weight));
        memset(cost,0,sizeof(cost));
        INC(i,1,n) scanf("%lld %lld",&weight[i],&cost[i]);
        printf("%lld\n",knapsack(n,0));
    }
    
 
    return 0 ;
}