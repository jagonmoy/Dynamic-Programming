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
ll n ;
char name = 'A';
vector < VL > dp ;
vector < VL > bracket ;
void printParenthesis(ll i , ll j) {
     if ( i == j) {
         cout << name++ ;  
         return ;
     }
     cout << "(" ;
     printParenthesis(i,bracket[i][j]); 
     printParenthesis(bracket[i][j]+1,j);
     cout << ")" ;
}
ll MCM(ll i, ll j) {
   if ( i >= j) return dp[i][j] = 0 ;
   if ( dp[i][j] != -1) return dp[i][j] ;
   dp[i][j] = inf;
   INC(k,i,j-1) {
       ll tempans = MCM(i,k) + MCM(k+1,j) + (v[i-1]*v[k]*v[j]);
       if ( tempans < dp[i][j]) {
           dp[i][j] = tempans ;
           bracket[i][j] = k ;
       }  
   }
   return dp[i][j] ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    v.resize(n+5,0);
    INC(i,1,n) cin >> v[i] ;
    dp.resize(n+5,VL (n+5,-1));
    bracket.resize(n+5,VL (n+5,-1));
    cout << MCM(2,n) << endl;
    printParenthesis(2,n);
    return 0 ;
}