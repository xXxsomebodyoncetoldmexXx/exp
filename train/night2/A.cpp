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

bool connectable(pair<ll, ll> x, pair<ll, ll> y){
  if(abs(x.fi - y.fi) >= (x.se+y.se))
    return true;
  return false;
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y){
  if(x.se != y.se)
    return x.se < y.se;
  return x.fi < y.fi;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll n;
  cin >> n;
  vector<pair<ll, ll>> pos(n);
  ll a, b;
  for(auto &i : pos){
    cin >> a >> b;
    i.fi = a-b;
    i.se = b+a;
  }
  if(n == 1){
    cout << 1;
    exit(0);
  }
  sort(ALL(pos), cmp);
  // for(auto i : pos)
  //   cout << i.fi << sp << i.se << el;
  ll ans = 1;
  pair<ll, ll> cur = pos[0];
  for(ll i = 1; i < n; i++){
    if(pos[i].fi >= cur.se){
      cur = pos[i];
      ans++;
    }
  }
  cout << ans;
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
