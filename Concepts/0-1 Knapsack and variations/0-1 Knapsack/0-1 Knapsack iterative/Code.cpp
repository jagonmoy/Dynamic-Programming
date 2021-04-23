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
VL weightArray,profitArray ;
ll numberOfelements,CapacityOfBag;
vector < VL > dp ;
ll knapsack() {
     
    for ( ll i = 0 ; i <= numberOfelements ; i++) {
        for ( ll j = 0 ; j <= CapacityOfBag ; j++) {
            if ( i == 0 || j == 0) dp[i][j] = 0 ; 
        } 
    } 

    for ( ll i = 1 ; i <= numberOfelements ; i++) {
        for ( ll j = 1 ; j <= CapacityOfBag ; j++) {
            if ( weightArray[i] <= j ) {
                dp[i][j] = max(profitArray[i]+dp[i-1][j-weightArray[i]],dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> numberOfelements >> CapacityOfBag ;
    
    dp.resize(numberOfelements+5 , VL (CapacityOfBag+5,-1));
    weightArray.resize(numberOfelements+5,0);
    profitArray.resize(numberOfelements+5,0);

    INC(i,1,numberOfelements) cin >> weightArray[i] ;
    INC(i,1,numberOfelements) cin >> profitArray[i];       
    
    knapsack() ;

    cout << dp[numberOfelements][CapacityOfBag] << endl;

    return 0 ;
}