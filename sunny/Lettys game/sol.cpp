//#define NDEBUG
#include <bits/stdc++.h>

using namespace std ;

//----------------------------------------------------------------------------------------------------------------------------------------------

typedef long long int LLI ;
typedef long double LD ;
typedef pair < int , int > PII ;
typedef pair < LLI , LLI > PLLILLI ;

typedef vector < int > VI ;
typedef vector < LLI > VLLI ;
typedef vector < bool > VB ;
typedef vector < string > VS ;
typedef vector < float > VF ;
typedef vector < double > VD ;
typedef vector < LD > VLD ;
typedef vector < PII > VPII ;
typedef vector < PLLILLI > VPLLILLI ;

typedef vector < VI > VVI ;
typedef vector < VVI > VVVI ;
typedef vector < VVVI > VVVVI ;
typedef vector < VLLI > VVLLI ;
typedef vector < VVLLI > VVVLLI ;
typedef vector < VVVLLI > VVVVLLI ;
typedef vector < VB > VVB ;
typedef vector < VS > VVS ;
typedef vector < VF > VVF ;
typedef vector < VD > VVD ;
typedef vector < VLD > VVLD ;
typedef vector < VPII > VVPII ;
typedef vector < VPLLILLI > VVPLLILLI ;

typedef set < int > SI ;
typedef set < LLI > SLLI ;
typedef set < PII > SPII ;
typedef set < PLLILLI > SPLLILLI ;
typedef set < string > SS ;

typedef unordered_set < int > USI ;
typedef unordered_set < LLI > USLLI ;
typedef unordered_set < PII > USPII ;
typedef unordered_set < PLLILLI > USPLLILLI ;
typedef unordered_set < string > USS ;

typedef map < int , int > MII ;
typedef map < LLI , LLI > MLLILLI ;
typedef map < int , PII > MIPII ;
typedef map < PII , PII > MPIIPII ;
typedef map < PII , int > MPIII ;
typedef map < int , string > MIS ;
typedef map < string , int > MSI ;
typedef map < string , string > MSS ;

typedef unordered_map < int , int > UMII ;
typedef unordered_map < LLI , LLI > UMLLILLI ;
typedef unordered_map < int , PII > UMIPII ;
typedef unordered_map < PII , PII > UMPIIPII ;
typedef unordered_map < PII , int > UMPIII ;
typedef unordered_map < int , string > UMIS ;
typedef unordered_map < string , int > UMSI ;
typedef unordered_map < string , string > UMSS ;

#define FIE(i,start,stop) for ( int i = start , _stop = stop ; i < _stop ; i ++ )

#define INF 1000000000
#define LINF 1000000000000000000LL
#define ERROR 0.00000001

//----------------------------------------------------------------------------------------------------------------------------------------------

const int N = 1e9 , M = 100000 ;
int n , m , x ;

int solve ( int x , int n ){
    if ( n == 1 ){
        return 1 ;
    }
    if ( x % 2 ){
        return n / 2 + solve ( ( x + 1 ) / 2 , ( n + 1 ) / 2 ) ;
    }
    else{
        return solve ( x / 2 , n / 2 ) ;
    }
    return - INF ;
}

int main (){
    cin >> n >> m ;
    FIE ( i , 0 , m ){
        cin >> x ;
        x = solve ( x , n ) ;
        cout<<x<<" "<<n<<"\n";
    }
    return 0 ;
}