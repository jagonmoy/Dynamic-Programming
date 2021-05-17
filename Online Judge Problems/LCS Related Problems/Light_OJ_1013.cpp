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
string s1,s2 ;
ll dp[35][35];
ll ways[35][35];

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t ;
    scanf("%lld",&t);
    ll cs = 0 ;
    while(t--) {
        cin >> s1 >> s2 ;
        ll len1 = s1.length();
        ll len2 = s2.length();
        memset(dp,-1,sizeof(dp));
        INC(i,0,len1) {
            INC(j,0,len2) {
                if ( i == 0 || j == 0) dp[i][j] = 0 ;
                else if ( s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("Case %lld: ",++cs);
        cout << len1+len2-dp[len1][len2] << " " ;
        memset(ways,-1,sizeof(ways));
        INC(i,0,len1) {
            INC(j,0,len2) {
                if ( i == 0 || j == 0) ways[i][j] = 1 ;
                else if ( s1[i-1] == s2[j-1]) ways[i][j] = ways[i-1][j-1];
                else {
                    if ( dp[i-1][j] > dp[i][j-1]) ways[i][j] = ways[i-1][j];
                    else if ( dp[i-1][j] < dp[i][j-1]) ways[i][j] = ways[i][j-1];
                    else ways[i][j] = ways[i-1][j] + ways[i][j-1];
                }
            }
        }
        cout << ways[len1][len2] << endl;
    }   
 
    return 0 ;
}