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

#define FASTIO              ios_base::sync_with_stdio(false),cin.tie(NULL)
#define rep(i, a, b)        for(ll i = (a), _b = (b); i <= _b; i++)
#define repv(i, a, b)       for(ll i = (a), _b = (b); i >= _b; i--)
#define repa(i, obj)        for(auto i : obj)
#define mp                  make_pair
#define mt                  make_tuple
#define pb                  push_back
#define fi                  first
#define se                  second
#define lb                  lower_bound
#define ub                  upper_bound
#define prs(n)              cout << fixed << setprecision(n)
#define el                  "\n"
#define sp                  " "
#define ALL(v)              (v).begin(), (v).end()
#define LXCMP(s, t)         lexicographical_compare(ALL(s), ALL(t))  // s > t
#define RALL(v)             (v).rbegin(), (v).rend()
#define MAXVAL(T)           numeric_limits<(T)>::max()
#define INF(T)              numeric_limits<(T)>::infinity()
#define MASK(i)             (1LL << (i))
#define BIT(x, i)           (((x) >> (i)) & 1)
#define div                 ___div
#define next                ___next
#define prev                ___prev
#define left                ___left
#define right               ___right
#define bitcount(n)         __builtin_popcountll(n)


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

/*  CODE BEGIN FROM HERE  */
vector<ll> pow1, pow2;
const ll P1 = 52819;
const ll P2 = 637;
const ll MOD1 = 1000*1000*1000 + 9;
const ll MOD2 = 1000*1000*1000 + 7;

#define mul(a, b, m) ((((a)%(m))*((b)%(m)))%m)
#define add(a, b, m) ((((a)%(m))+((b)%(m)))%m)

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  string s;
  cin >> s;
  ll ans = 0;

  pow1.pb(1);
  pow2.pb(1);
  for(ll i = 1; i < s.size(); i++){
    pow1.pb(mul(pow1.back(), P1, MOD1));
    pow2.pb(mul(pow2.back(), P2, MOD2));
  }

  vector<ll> H1rev(s.size() + 1, 0);
  vector<ll> H2rev(s.size() + 1, 0);
  
  for(ll i = s.size()-1; i>=0; i--){
    H1rev[i] = add(mul(H1rev[i+1], P1, MOD1), s[i], MOD1);
    H2rev[i] = add(mul(H2rev[i+1], P2, MOD2), s[i], MOD2);
  }
  for(ll i = 0; i <= s.size(); i++)
    cout << i << sp << H1rev[i] << el;
  cout << "=========" << el;
  for(ll i = 0; i < s.size(); i++)
    cout << i << sp << pow1[i] << el;
  cout << "=========" << el;
  ll lf;
  ll h1, h2, r1, r2;
  h1 = h2 = 0;
  for(ll i = 0; i < s.size(); i++){
    lf = (i+1)>>1;
    if(i&1){
      h1 = (h1*P1 + s[lf-1])%MOD1;
      h2 = (h2*P2 + s[lf-1])%MOD2;
    }
    cout << i-lf+1 << sp << i+1 << el;
    // cout << h1 << sp << h2 << el;  
    // r1 = H1rev[i-l+1]
  } 

  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
