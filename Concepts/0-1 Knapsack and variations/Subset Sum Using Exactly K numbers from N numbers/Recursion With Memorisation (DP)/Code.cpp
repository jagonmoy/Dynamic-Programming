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

VL v ;
vector < vector < VL > > dp ;
ll K_subsetSum(ll i , ll sum , ll cnt) {
    if ( sum == 0 && cnt == 0) return dp[i][sum][cnt] =  1 ; 
    else if ( sum != 0 && cnt == 0) return dp[i][sum][cnt] = 0 ;
    else if ( sum == 0 && cnt != 0) return dp[i][sum][cnt] = 0 ;
    else if ( i == 0) return dp[i][sum][cnt] = 0 ;
    else if ( i < cnt) return dp[i][sum][cnt] = 0 ;

    if (dp[i][sum][cnt] != -1) return dp[i][sum][cnt] ;
    
    if ( v[i] <= sum) 
        return dp[i][sum][cnt] = (K_subsetSum(i-1,sum-v[i],cnt-1) + K_subsetSum(i-1,sum,cnt));
    else return dp[i][sum][cnt] = K_subsetSum(i-1,sum,cnt) ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,sum ;
    cin >> n >> k >> sum ;
    v.resize(n+5,0);
    dp.resize(n+5);
    INC(i,0,n+4) {
        dp[i].resize(sum+5);
        INC(j,0,sum+4) {
            dp[i][j].resize(k+5,-1);
        }
    }     
    INC(i,1,n) cin >> v[i];
    cout << K_subsetSum(n,sum,k) << endl;
    
    return 0 ;
}