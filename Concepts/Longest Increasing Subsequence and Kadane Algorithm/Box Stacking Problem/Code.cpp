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
vector < pair < ll,PLL> > boxes ;
bool myfunc(pair < ll,PLL> x , pair < ll,PLL> y) {
    return ( (x.S.S * x.S.F) > (y.S.S * y.S.F)) ; 
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll noOfBoxes ;
    cin >> noOfBoxes ;
    INC(i,1,noOfBoxes) {
        ll d1,d2,d3 ;
        cin >> d1 >> d2 >> d3 ;
        boxes.PB({d1,{max(d2,d3),min(d2,d3)}});
        boxes.PB({d2,{max(d1,d3),min(d1,d3)}});
        boxes.PB({d3,{max(d1,d2),min(d1,d2)}});
    }
    sort(boxes.begin(),boxes.end(),myfunc); 
    VL lisBoxes ;
    lisBoxes.resize(boxes.size()+5,0);
    ll maxHeight = -1 ;
    INC(i,0,boxes.size()-1) {
        lisBoxes[i] = boxes[i].F ;
        maxHeight = max(maxHeight,lisBoxes[i]);
    }
    
    INC(i,1,boxes.size()-1) {
        INC(j,0,i-1) {
            if ( boxes[i].S.F < boxes[j].S.F && boxes[i].S.S < boxes[j].S.S && lisBoxes[j]+boxes[i].F > lisBoxes[i]) {
                lisBoxes[i] = lisBoxes[j]+boxes[i].F ;
                maxHeight = max(maxHeight,lisBoxes[i]);
            }
        }
    }  
    cout << "Maximum Height is : " << maxHeight << endl;
 
    return 0 ;
}