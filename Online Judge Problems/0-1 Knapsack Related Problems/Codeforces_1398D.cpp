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
VL arrR,arrG,arrB ;
vector < vector < VL > > dp ;
ll knapsack(ll i, ll j, ll k) {

    if ( i+j == 0 || j+k == 0 || i+k == 0 ) return 0 ;
    if ( dp[i][j][k] != -1) return dp[i][j][k] ;
    ll val = 0 ;
    if ( i != 0 && j != 0 ) val = max(val,arrR[i-1]*arrG[j-1] + knapsack(i-1,j-1,k));
    if ( i != 0 && k != 0 ) val = max(val,arrR[i-1]*arrB[k-1] + knapsack(i-1,j,k-1));
    if ( j != 0 && k != 0 ) val = max(val,arrG[j-1]*arrB[k-1] + knapsack(i,j-1,k-1));
    return dp[i][j][k] = val ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll r,g,b ;
    cin >> r >> g >> b ;
    INC(i,0,r-1) {
        ll a ;
        cin >> a ;
        arrR.PB(a);
    }

    INC(i,0,g-1) {
        ll a ;
        cin >> a ;
        arrG.PB(a);
    }
    
    INC(i,0,b-1) {
        ll a ;
        cin >> a ;
        arrB.PB(a);
    }
    sort(arrR.begin(),arrR.end());
    sort(arrG.begin(),arrG.end());
    sort(arrB.begin(),arrB.end());
    ll sizeR = arrR.size() ;
    ll sizeG = arrG.size() ;
    ll sizeB = arrB.size() ;
    dp.resize(sizeR+5);
    INC(i,0,sizeR+4) {
        dp[i].resize(sizeG+5);
        INC(j,0,sizeG+4) {
            dp[i][j].resize(sizeB+5,-1);
        }
    }
    cout << knapsack(sizeR,sizeG,sizeB) << endl;

    return 0 ;
}