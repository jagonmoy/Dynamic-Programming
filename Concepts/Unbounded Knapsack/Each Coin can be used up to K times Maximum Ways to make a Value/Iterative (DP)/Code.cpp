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
VL CoinArray;
ll CoinNumbers , amount, k ;
vector < vector < VL > > dp ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> amount >> CoinNumbers >> k;
    CoinArray.resize(CoinNumbers+5,0);   
    INC(i,1,CoinNumbers) cin >> CoinArray[i];
    dp.resize(CoinNumbers+5);
    INC(i,0,CoinNumbers+4) {
        dp[i].resize(amount+5);
        INC(j,0,amount+4) {
            dp[i][j].resize(k+4,-1);
        }
    }
    INC(j,0,amount) {
        INC(l,0,k) {
            dp[0][j][l] = 0 ;
        }
    }
    INC(i,0,CoinNumbers) {
        INC(l,0,k) {
           dp[i][0][l] = 1 ;
        }
    }

    INC(i,1,CoinNumbers) {
        INC(j,1,amount) {
            INC(l,0,k) {
                if ( CoinArray[i] <= j && l != 0) {
                    dp[i][j][l] = dp[i][j-CoinArray[i]][l-1] + dp[i-1][j][k]; 
                }
                else dp[i][j][l] = dp[i-1][j][k];
            }
        }
    } 


    cout << dp[CoinNumbers][amount][k] << endl;
    return 0 ;
}