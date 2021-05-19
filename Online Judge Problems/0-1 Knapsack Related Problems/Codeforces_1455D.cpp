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
int n;
vector <int> v ;
vector < vector < vector <int> > > dp;
int knapsack(int i,int prev,int x ) {

   if ( i > n) return 0 ;
   if ( v[i] < prev) return 505 ;

   if ( dp[i][prev][x] != -1 ) return dp[i][prev][x] ;

   if ( v[i] >= prev && x < prev) return dp[i][prev][x] = knapsack(i+1,v[i],x);
   else if ( v[i] < prev && x >= prev) return dp[i][prev][x] = 1+knapsack(i+1,x,v[i]);
   else if ( v[i] < prev && x < prev) return dp[i][prev][x] = 505 ;
   else return dp[i][prev][x] = min(knapsack(i+1,v[i],x),1+knapsack(i+1,x,v[i]));
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t ;
    while(t--) {
        int x ;
        cin >> n >> x ;
        v.clear();
        v.resize(n+5,0);
        for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
        dp.clear();
        dp.resize(n+5);

        INC(i,0,n+4) {
            dp[i].resize(502);
            INC(j,0,501) {
                dp[i][j].resize(502,-1);
            }
        }
        
        int val = knapsack(1,0,x);
        if ( val >= 505) val = -1 ;
        cout << val << endl;
    }
  
    return 0 ;
}