#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define PF push_front
#define P push
#define INC(i,a,b) for (ll i = a; i <= b; i++)
#define DEC(i,b,a) for (ll i = b; i >= a ; i--)
#define inf 999999999999
#define neginf -999999999
#define mod  1000000007
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
     return (a*b)/gcd ;
}
VL coins,limit ;
ll ways[55][1005];
ll n,k ;
ll f(ll i,ll val) {
    if ( val == 0) return 1 ;
    if ( i == n) return 0 ;
    if ( ways[i][val] != -1) return ways[i][val];
    ways[i][val] = 0 ;
    for ( ll j = 0 ; j <= limit[i] && val-coins[i]*j >= 0 ; j++) {
        ways[i][val] = (ways[i][val] + f(i+1,val-coins[i]*j))%100000007 ;
    }
    return ways[i][val]%100000007;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    scanf("%lld",&t);
    ll caseno = 0 ;
    while(t--) {
        memset(ways,-1,sizeof(ways));
        scanf("%lld %lld",&n,&k);
        INC(i,0,n-1) {
            ll a ;
            scanf("%lld",&a);
            coins.PB(a);
        }
        INC(i,n,2*n-1) {
            ll a ;
            scanf("%lld",&a);
            limit.PB(a);
        }
        printf("Case %lld: %lld\n",++caseno,f(0,k));
        coins.clear();
        limit.clear();
    }
 
    return 0 ;
}