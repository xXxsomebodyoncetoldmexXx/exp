#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI = 3.141592653589793238462643383279502884;
const double esp = 1e-9;

using namespace std;
  
#ifdef LOCAL_PROJECT
  #define CURTIME()         cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
  #define INFILE(name)      freopen(name, "r", stdin)
  #define OUFILE(name)      freopen(name, "w", stdin)
  #define DEBUG             cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
  #define DUMP(value)       cerr << "[" << (#value) << "]: " << (value) << el
#else
  #define CURTIME()         ;
  #define INFILE(name)      ;
  #define OUFILE(name)      ;
  #define DEBUG             ;
  #define DUMP(value)       ;
#endif

#define FASTIO             ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mp                 make_pair
#define mt                 make_tuple
#define pb                 push_back
#define fi                 first
#define se                 second
#define lb                 lower_bound
#define ub                 upper_bound
#define prs(n)             cout << fixed << setprecision(n)
#define el                 "\n"
#define sp                 " "
#define ALL(v)             (v).begin(), (v).end()
#define LXCMP(s, t)        lexicographical_compare(ALL(s), ALL(t))  // s > t
#define RALL(v)            (v).rbegin(), (v).rend()
#define MAXVAL(T)          numeric_limits<(T)>::max()
#define INF(T)             numeric_limits<(T)>::infinity()
#define MASK(i)            (1LL << (i))
#define BIT(x, i)          (((x) >> (i)) & 1)
#define div                ___div
#define next               ___next
#define prev               ___prev
#define left               ___left
#define right              ___right
#define bitcount(n)        __builtin_popcountll(n)


// RNG - for sum fun
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/**********************************
*  Combination calculate          *
*  Note to self: n >= r           *
*  From N pieces pick R pieces    *
*  The fomular: n! / (r! * (n-r)!)*
*  Complexity: O(r)               *
***********************************/
ll nCr(ll n, ll r){
  ll tmp = n-r;
  for(ll i = n-1; i > tmp; i--)
    n *= i;
  for(ll i = r-1; i > 1; i--)
    r *= i;
  return n/r;
}

ll MOD = 1000000007;

// ll add(ll a, ll b){
//   return (a+b)%MOD;
// }

// ll mul(ll a, ll b){
//   return ((a%MOD)*(b%MOD))%MOD;
// }

#define add(a, b) ((((a)%MOD) + ((b)%MOD))%MOD)
#define mul(a, b) ((((a)%MOD) * ((b)%MOD))%MOD)

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  //OUFILE("out");

  ll a, b;
  cin >> a >> b;
  ll ans=0;
  ll thing = (b*(b-1)/2)%MOD;
  ll conB = b;
  ll tmp;
  for(ll i = 1; i <= a; i++){
    // ans = add(ans, mul(mul(b, i) + 1, thing));
    ans = add(ans, mul(conB+1, thing));
    conB = add(conB, b);
  }
  cout << ans;
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
