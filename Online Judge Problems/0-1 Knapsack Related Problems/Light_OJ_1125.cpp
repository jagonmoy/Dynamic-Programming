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
ll v[205];
ll n,m,p,q ;
ll dp[205][25][15] ;
ll divisble_by_m(ll CurrentN, ll CurrentM , ll CurrentP) {
    if ( CurrentM == 0 && CurrentP == 0) return dp[CurrentN][CurrentM][CurrentP] = 1 ;
    else if ( CurrentM != 0 && CurrentP == 0) return dp[CurrentN][CurrentM][CurrentP] =0 ;
    else if (CurrentN == 0) return dp[CurrentN][CurrentM][CurrentP] = 0 ;
    else if ( CurrentN < CurrentP) return dp[CurrentN][CurrentM][CurrentP] = 0 ;
    if ( dp[CurrentN][CurrentM][CurrentP] != -1) return dp[CurrentN][CurrentM][CurrentP];
    ll val = (CurrentM+v[CurrentN])%m;
    if ( val < 0) val += m ;
    return dp[CurrentN][CurrentM][CurrentP] = divisble_by_m(CurrentN-1,val,CurrentP-1)
           + divisble_by_m(CurrentN-1,CurrentM%m,CurrentP);       
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    ll cs = 0 ;
    while(t--) {
        cin >> n >> q ;
        memset(v,0,sizeof(v));
        INC(i,1,n) cin >> v[i];  
        cout << "Case " << ++cs << ":" << endl; 
        INC(i,1,q) {
            cin >> m >> p ;
            memset(dp,-1,sizeof(dp));
            cout << divisble_by_m(n,0,p) << endl;
        }
    }
 
    return 0 ;
}