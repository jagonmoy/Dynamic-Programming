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
string s ;
ll len ;
ll booleanParenthesize(ll i , ll j , bool fact) {
    if ( i > j) return 0 ;
    if ( i == j) {
        if(fact) {
            if ( s[i] == 'T') return 1 ;
            else return 0 ;
        }
        else {
            if ( s[i] == 'F') return 1 ;
            else return 0 ;
        }
    }
    ll ans = 0 ;
    for ( ll k = i+1 ; k <= j-1 ; k = k+2) {
        ll leftTrue = booleanParenthesize(i,k-1,true);
        ll leftFalse = booleanParenthesize(i,k-1,false);
        ll rightTrue = booleanParenthesize(k+1,j,true);
        ll rightFalse = booleanParenthesize(k+1,j,false);
        if ( s[k] == '&') {
            if (fact) ans += (leftTrue*rightTrue);
            else ans += (leftTrue*rightFalse)+(leftFalse*rightTrue)+(leftFalse*rightFalse);
        }
        else if ( s[k] == '|') { 
            if (fact) ans += (leftTrue*rightFalse) + (leftTrue*rightTrue) + (leftFalse*rightTrue);
            else ans += (leftFalse*rightFalse);
        }
        else if ( s[k] == '^') {
            if (fact) ans += (leftTrue*rightFalse) + (leftFalse*rightTrue);
            else ans += (leftFalse*rightFalse) + (leftTrue*rightTrue);
        }
    }
    return  ans ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s ;
    len = s.size()-1 ;
    cout << booleanParenthesize(0,len,true) << endl;    
 
    return 0 ;
}