  
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
 
ll cost[2005];
ll weight[2005];
ll dp[2005][2005];
 
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
ll knapsack(ll i , ll w) {
    if ( w == 0 || i == 0) return 0 ;
    if ( dp[i][w] != -1) return dp[i][w];
    if ( weight[i] <= w) {
        return dp[i][w] = max(cost[i] + knapsack(i-1,w-weight[i]),knapsack(i-1,w));
    }
    else return dp[i][w] = knapsack(i-1,w) ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll capacity,itemnumbers ;
    cin >> capacity >> itemnumbers ;
    memset(dp,-1,sizeof(dp));
    INC(i,1,itemnumbers) {
        ll w,c ;
        cin >> w >> c ;
        weight[i] = w ;
        cost[i] = c ;
    }
    cout << knapsack(itemnumbers,capacity) << endl;
 
    return 0 ;
} 