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

inline vector<ll> operator+(vector<ll> &u, vector<ll> &v){
  ull i, j;
  vector<ll> ret;
  for(ull i = 0; i < u.size(); i++)
    ret.pb(u[i] + v[i]);
  return ret;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> maxt;
  pair<ll, ll> good = mp(-1, -1);
  for(ll i = 0; i < k; i++){
    vector<ll> tmp(n);
    ll mx = -1;
    for(auto &i : tmp)
      cin >> i;
    for(ll i = 0; i < n-1; i++)
      mx = max(mx, tmp[i]);
    if(mx > good.se && mx >= tmp[n-1])
      good = mp(i, mx);
    maxt.pb(tmp);
  }
  cout << good.fi << sp << good.se << el;
  if(good.fi == -1){
    cout << k << el;
    for(ll i = 1; i<= k; i++)
      cout << i << sp;
  }
  else{
    map<ll, bool> ele;
    ele[good.fi] = true;
    bool choose;
    while(true){
      choose = false;

      for(ll i = 0; i < k; i++){
        if(ele[i] == false){

        }
      }

      if(!choose)
        break;
    }
    vector<ll> ans;
    for(ll i = 1; i <= k; i++)
      if(ele[i] == false)
        ans.pb(i+1);
    cout << ans.size() << el;
    for(auto i : ans)
      cout << i << sp;
  }
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
