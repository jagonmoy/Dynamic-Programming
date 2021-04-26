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
vector < VL > dp ;
VL subset ;
ll subset_sum(ll i, ll val) {
    if ( val == 0 ) return 1 ;
    if ( i == 0 ) return 0 ;
    if ( dp[i][val] != -1) return dp[i][val];
    if ( subset[i] <= val)
        return dp[i][val] = subset_sum(i-1,val-subset[i]) || subset_sum(i-1,val);
    else return dp[i][val] = subset_sum(i-1,val);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    while(t--) {
        ll n ;
        cin >> n ;
        SL s ;
        VL v ;
        INC(i,1,2*n) {
            s.insert(i);
            ll a ;
            cin >> a ;
            v.PB(a);
        }
        subset.PB(0);
        auto it  = s.end() ;
        it-- ;
        ll maximum = *it ;
        ll cnt = 0 ;
        DEC(i,v.size()-1,0) {
            if ( v[i] != maximum) {
                s.erase(v[i]);
                cnt++ ;
            }
            else {
                s.erase(v[i]);
                cnt++ ;
                subset.PB(cnt);
                if ( s.size() != 0) {
                auto it2  = s.end() ;
                it2-- ;
                maximum = *it2 ;
                cnt = 0 ;
                }
            }   
        }
        dp.resize(subset.size()+5, vector<ll>(n+5,-1));
        if ( subset_sum(subset.size()-1,n)) cout << "YES" << endl;
        else cout << "NO" << endl;
        subset.clear();
        dp.clear();
    }

    return 0 ;
}