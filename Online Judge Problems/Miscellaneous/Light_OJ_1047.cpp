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
vector < VL > cost ;
ll n ;
vector <VL> dp ;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    ll cs = 0 ;
    while(t--) {
        cin >> n ;
        cost.clear();
        cost.resize(n+5);
        INC(i,0,n+4) {
            cost[i].resize(5,0);
        }
        dp.clear();
        dp.resize(n+5);
        INC(i,0,n+4) {
            dp[i].resize(5,inf);
        }

        INC(i,1,n) {
            ll a,b,c ;
            cin >> a >> b >> c ;
            cost[i][1] = a ;
            cost[i][2] = b ;
            cost[i][3] = c ;
        }
        INC(i,1,3) dp[0][i] = 0 ;
        INC(i,1,n) {
            INC(j,1,3) {
                INC(k,1,3) {
                    if ( j != k) {
                        dp[i][j] = min(dp[i][j],cost[i][j]+dp[i-1][k]);
                    }
                }
            }
        } 


        ll res = inf ;
        INC(i,1,3) res = min(res,dp[n][i]) ;
        cout << "Case " << ++cs << ": " << res << endl;
    }
 
    return 0 ;
}