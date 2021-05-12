#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define P push
#define INC(i,a,b) for (ll i = a; i <= b; i++)
#define DEC(i,b,a) for (ll i = b; i >= a ; i--)
#define inf 999999999
#define neginf -999999999
typedef ostringstream OS ;
typedef stringstream SS ;
typedef long long ll ;
typedef pair < ll , ll > PLL ;
typedef pair < char,ll > PCL ;
typedef vector < double > VDL;
typedef vector < PCL > VCL ;
typedef vector < ll > VL;
typedef vector < PLL > VLL ;
typedef vector < char > VC ;
typedef map < ll ,ll > MLL ;
typedef map < char,ll > MCL;
typedef priority_queue < PLL > PQLL ;
typedef priority_queue < ll > PQL ;
typedef stack < ll > SKL ;
typedef stack < PLL > SKLL ;
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
     return (a*b)/gcd ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n ;
    cin >> n ;
    VL v ;
    INC(i,0,n-1) {
        ll a ;
        cin >> a ;
        v.PB(a);
    }
    pair < ll ,PLL >  sum = {0,{0,0}};
    pair < ll ,PLL >  best = {neginf,{-1,-1}}; /* you can use best as {0,{0,0}} if it is allowed to 
                                                take empty subarray */
                                                     
    INC(i,0,n-1) {
        if ( v[i] >= sum.F + v[i]) {
            sum.S.F = i ;
            sum.S.S = i ;
            sum.F = v[i] ;
            if ( v[i] > best.F) {
                best.S.F = sum.S.F ;
                best.S.S = sum.S.S ;
                best.F = sum.F ;
            }
        }
        else if ( v[i]+sum.F > v[i]) {
            sum.S.S = i ;
            if ( v[i]+sum.F > best.F) {
                best.S.F = sum.S.F ;
                best.S.S = sum.S.S ;
                best.F = v[i] + sum.F ;
            }
            sum.F = v[i]+sum.F ;
        }
    }

    cout << best.F << " " << best.S.F+1 << " " << best.S.S+1 << endl;

    return 0 ;
}