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
ll n,k ;
VL noOfOnes ;
string s ;
vector < VL > dp ;
ll knapsack(ll i, ll state) {
    if ( i > n) {
        if (state) return noOfOnes[n]-noOfOnes[max(i-k,0ll)] ;
        else return noOfOnes[n]-noOfOnes[0];
    }
    if ( dp[i][state] != -1) return dp[i][state];
    if (state == 0) {
        ll val = 0 ;
        if ( s[i-1] == '0') val++ ;
        ll possibleVal1 = val+noOfOnes[i-1]-noOfOnes[0]+knapsack(i+k,1);
        ll possibleVal2 = knapsack(i+1,0);
        return dp[i][state] = min(possibleVal1,possibleVal2);   
    }
    else if ( state == 1 ) {
        ll val = 0 ;
        if ( s[i-1] == '0') val++ ; 
        ll possibleVal1 = val+noOfOnes[i-1] - noOfOnes[i-k]+knapsack(i+k,1);
        ll possibleVal2 = !val + noOfOnes[i-1] - noOfOnes[i-k] + knapsack(i+k,2);
        return dp[i][state] = min(possibleVal1,possibleVal2); 
    }
    else if ( state == 2) {
         ll val = 0 ;
         if ( s[i-1] == '1') val++ ;
         return dp[i][state] = val + noOfOnes[i-1] - noOfOnes[i-k] + knapsack(i+k,2);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    while(t--) {      
        cin >> n >> k ;      
        cin >> s ;
        dp.clear();
        dp.resize(n+5, VL (4,-1));
        noOfOnes.clear();
        noOfOnes.resize(n+5,0);
        ll cntOne = 0 ;
        INC(i,0,s.size()-1) {
            if ( s[i] == '1') cntOne++ ;
            noOfOnes[i+1] = cntOne ;
        }
       

        cout << knapsack(1,0) << endl;
    }
 
    return 0 ;
}