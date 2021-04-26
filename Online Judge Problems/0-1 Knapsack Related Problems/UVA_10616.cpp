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
ll n,m,k ;
ll subset[205];
ll dp[205][21][12];
ll divisble_by_m(ll i , ll sum , ll cnt) {
    //cout << i << " " << sum << " " << cnt << endl;
    if ( sum == 0 && cnt == k) return 1 ;
    if ( sum != 0 && cnt == k) return 0 ;
    if ( i > n) return 0 ;
    if ( dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
    ll val = (sum+subset[i])%m ;
    if ( val < 0) val += m ;
    return  dp[i][sum][cnt] = divisble_by_m(i+1,val,cnt+1) + divisble_by_m(i+1,sum%m,cnt) ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll c = 0 ;
    while(1) {
        ll q ;
        cin >> n >> q;
        if ( n == 0 && q == 0) break ;
        cout << "SET "<< ++c << ":" << endl;
        memset(subset,0,sizeof(subset));
        INC(i,1,n) cin >> subset[i];
        ll t = 0 ;
        while(q--) {
            memset(dp,-1,sizeof(dp));
            cin >> m >> k ;
            cout << "QUERY "<< ++t <<": " << divisble_by_m(1,0,0) << endl;
        }
    }
 
    return 0 ;
}