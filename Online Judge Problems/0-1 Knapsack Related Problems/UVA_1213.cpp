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
ll check[1125];
ll dp[200][1500][15] ;
DL primes ;
void sieve(ll n) {
    memset(check,0,sizeof(check));
    check[1] = 1 ;
    for ( ll i = 4 ; i <= n ; i = i+2) check[i] = 1 ;    //the numbers which are not prime that means even numbers are marked by 1

    for ( ll i = 3 ; i*i <= n ; i += 2) {                // Even numbers are not prime so we will check only odd numbers and increment the number by 2 to avoid even number.
        if (!check[i]) {                                 // if  check[i] = 0 that means if the i value is a prime we will procced
            for ( ll j = i*i ; j <= n ; j += 2*i){       // here we are starting not by j = i+i we are starting by j = i*i because the numbers less than i*i are already 
                   check[j] = 1 ;                        // checked by the numbers less than j so no need to calculate them further . and each time we will increment the
            }                                            // numbers by 2*i because if this is a odd number then just incrementing i it will be even and even numbers 
        }                                                // numbers are not prime so no need to check this .
    }   

    for ( ll i = 1 ; i <= n ; i++) {
         if (!check[i]) primes.PB(i); 
         check[i] = primes.size() ;
    }  
}

ll sum_of_k_different_primes(ll i , ll sum , ll cnt) {
    if ( sum == 0 && cnt == 0) return 1 ;
    if ( sum != 0 && cnt == 0) return 0 ;
    if ( i == 0) return 0 ;
    if ( dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
    if ( primes[i] <= sum) 
        return dp[i][sum][cnt] = sum_of_k_different_primes(i-1,sum-primes[i],cnt-1) + sum_of_k_different_primes(i-1,sum,cnt);
    else return dp[i][sum][cnt] = sum_of_k_different_primes(i-1,sum,cnt) ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(1120);
    primes.PF(0);
    while(1) {
        ll sum,cnt ;
        scanf("%lld %lld",&sum,&cnt);
        if ( sum == 0 && cnt == 0) break ;
        ll index = check[sum] ;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",sum_of_k_different_primes(index,sum,cnt));
    } 
    return 0 ;
}