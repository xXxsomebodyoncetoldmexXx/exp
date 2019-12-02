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
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define lxcmp(s, t)         lexicographical_compare(ALL(s), ALL(t))  // s > t
#define MAXVAL(T)           numeric_limits<(T)>::max()
#define INF(T)              numeric_limits<(T)>::infinity()
#define mask(i)             (1LL << (i))
#define bit(x, i)           (((x) >> (i)) & 1)
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

inline ll mul(ll a, ll b, ll MOD = (1LL<<62)){
  return ((((a)%MOD)*((b)%MOD))%MOD);
}

inline ll add(ll a, ll b, ll MOD = (1LL<<62)){
  return ((((a)%MOD)+((b)%MOD))%MOD);
}

inline ll Pow(ll base, ll exp, ll MOD = (1LL<<62)){
  ll ans = 1;
  while(exp){
    if(exp & 1)
      ans = (ans*base)%MOD;
    exp >>= 1;
    base = (base*base)%MOD;
  }
  return ans;
}

/*  CODE BEGIN FROM HERE  */

inline ll f(ll x, ll val){
  // x = mul(x, x);
  if(x > val)
    return 1;
  if(x == val)
    return 0;
  return -1;
}

ll binS(ll val, ll L = 1, ll R = (1LL<<62)){
  ll ans = -1;
  ll mid;
  ll sw;
  while(L <= R){
    mid = R-(R-L)/2;
    sw = f(mid, val);
    if(sw > -1){
      if(!sw)
        ans = mid;
      R = mid-1;
    }
    else
      L = mid+1;
  }
  return ans;
}

ll count(vector<ll> v, ll val){
  ll p, q, n;
  p = q = -1;
  n = v.size();
  for(ll step = n; step >= 1; step >>=1){
    while((p+step) < n && v[p+step] < val) p += step;
    while((q+step) < n && v[q+step] <=val) q += step;
  }
  return q-p;
}

double a = 0.0; 
double r = 100000000000000000000.0;
for (int it = 1; it <= 70; it++) { 
   double mid = (a + b) / 2.0;
   if (propertie(mid)) b = mid;
   else a = mid;
}
cout << b << endl;


int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll l, r, v;
  cin >> l >> r >> v;
  vector<ll> test = {1,2,2,2,2,3,3,3,3,3,4,5,6,7};
  cout << count(test, v);
  
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
