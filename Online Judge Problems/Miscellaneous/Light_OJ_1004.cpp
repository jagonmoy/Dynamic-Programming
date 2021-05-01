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
vector < VL > dp ;
vector < VL > cost;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    ll cs = 0 ;
    cin >> t ;
    while(t--) {
        ll n ;
        cin >> n ;
        dp.clear();
        dp.resize(2*n+2);
        INC(i,0,2*n+1) {
            dp[i].resize(n+2,-1);
        }
        cost.clear();
        cost.resize(2*n+2);
        INC(i,0,2*n+1) {
            cost[i].resize(n+2,-1);
        }
        
        INC(i,1,2*n-1) {
           if ( i <= n-1) {
               INC(j,1,i) {
                   cin >> cost[i][j];
               }
           }
           else {
               INC(j,1,2*n-i) {
                   cin >> cost[i][j];
               }  
           }
        }
 
        dp[0][0] = 0 ; 
        INC(i,1,2*n-1) {
           if ( i <= n) {
               INC(j,1,i) {
                   ll val1 = 0,val2 = 0 ;
                   if ( j-1 >= 0) val1 = cost[i][j]+dp[i-1][j-1];
                   if (j <= i) val2 = cost[i][j]+dp[i-1][j];
                   dp[i][j] = max(val1,val2);
               }
           }
           else {
               INC(j,1,2*n-i) {
                   ll val1 = 0,val2 = 0 ;
                   val1 = cost[i][j] + dp[i-1][j];
                   val2 = cost[i][j] + dp[i-1][j+1];
                   dp[i][j] = max(val1,val2);
               }  
           }
        }
        

        cout << "Case " << ++cs << ": " << dp[2*n-1][1] << endl;
    }



 
    return 0 ;
}