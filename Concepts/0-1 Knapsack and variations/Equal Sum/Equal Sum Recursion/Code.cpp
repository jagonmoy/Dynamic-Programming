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
bool Equalsum(ll currentIndex , ll currentCapacity) {
    if ( currentCapacity == 0) return true ;
    if ( currentIndex == 0) return false ;
    if ( v[currentIndex] <= currentCapacity) {
        return ( Equalsum(currentIndex-1,currentCapacity-v[currentIndex]) || Equalsum(currentIndex-1,currentCapacity));
    }
    else return Equalsum(currentIndex-1,currentCapacity);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll numberOfElements ;
    cin >> numberOfElements ;
    v.resize(numberOfElements+5,0);
    ll totalsum = 0 ;
    INC(i,1,numberOfElements) {
        cin >> v[i];
        totalsum += v[i];
    }
    if ( totalsum %2 == 1) cout << "NO" << endl;
    else {
        totalsum /= 2 ;
        if (Equalsum(numberOfElements,totalsum)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0 ;
}