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
string  s ;
vector < VL > dp ;
bool isPalindrom(ll i, ll j) {
    bool fact = true ;
    while(i <= j) {
        if ( s[i] != s[j]) {
            fact = false ;
            break ;
        }
        i++ ;
        j-- ;
    }
    return fact ;
}
ll palindromePartition(ll i, ll j) {
    if ( i == j) return dp[i][j] = 0 ;
    if ( dp[i][j] != -1) return dp[i][j];
    if (isPalindrom(i,j)) return dp[i][j] = 0 ;
    ll minimum = inf ;
    INC(k,i,j-1) {
        ll temp = palindromePartition(i,k) + palindromePartition(k+1,j) +1 ;
        minimum = min(temp,minimum);
    }
    return dp[i][j] = minimum ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s ;
    ll len = s.size()-1;
    dp.resize(len+5, VL(len+5,-1));
    cout << palindromePartition(0,len) << endl;        
 
    return 0 ;
}