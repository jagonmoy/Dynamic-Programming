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
ll n,h,l,r ;
VL sleep ;
vector < VL > dp ;
ll knapsack(ll i, ll t) {
    
    if ( i == n) return 0 ;

    if ( dp[i][t] != -1) return dp[i][t]; 
    ll res = -1 ;

    ll val1 = (t + sleep[i])%h ; 
    if ( val1 <= r && val1 >= l ) res = max(res,1+knapsack(i+1,val1));
    else res = max(res,knapsack(i+1,val1));

    ll val2 = (t + sleep[i]-1)%h;
    if ( val2 <= r && val2 >= l ) res = max(res,1+knapsack(i+1,val2));
    else res = max(res,knapsack(i+1,val2));

    return dp[i][t] = res ; 
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> h >> l >> r ;
    INC(i,1,n) {
        ll a ;
        cin >> a ;
        sleep.PB(a);
    }
    dp.clear();
    dp.resize(n+5 , VL(h+5 , -1));
    cout << knapsack(0,0) << endl;
 
    return 0 ;
}