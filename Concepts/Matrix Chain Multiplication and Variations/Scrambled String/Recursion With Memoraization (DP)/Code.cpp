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
map < pair <string,string> , bool > mymap ;
bool isScrambled(string s1, string s2) {
    if ( s1.size() != s2.size()) return mymap[{s1,s2}] = false ;
    if ( s1.size() == 0) return mymap[{s1,s2}] = false ;
    if (s1 == s2 ) return mymap[{s1,s2}] = true ;
    if ( s1.size() == 1) return mymap[{s1,s2}] = false ;
    if ( mymap.find({s1,s2}) != mymap.end()) return mymap[{s1,s2}];
    ll len1 = s1.size();
    ll len2 = s2.size();
    bool ultimatefact = false ;
    INC(i,1,s1.size()-1) {
        bool fact1 = isScrambled(s1.substr(0,i),s2.substr(0,i));
        bool fact2 = isScrambled(s1.substr(i,len1-i),s2.substr(i,len2-i)) ; 
        if ( fact1 && fact2) {
            ultimatefact = true ;
            break ;
        }
        bool fact3 = isScrambled(s1.substr(0,i),s2.substr(len2-i,i));
        bool fact4 = isScrambled(s1.substr(len1-i,i),s2.substr(0,i)); 
        if ( fact3 && fact4) {
            ultimatefact = true ;
            break ;
        }
    }
    return mymap[{s1,s2}] = ultimatefact;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  
    cin >> s1 >> s2 ;
    if (isScrambled(s1,s2)) cout << "YES" << endl;
    else cout << "NO" << endl;
 
    return 0 ;
}