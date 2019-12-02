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

// db heron(db x, db y, db z){
//   db s = (x+y+z)/2.0;
//   return sqrt(s * (s-x) * (s-y) * (s-z));
// }

// db distant(pair<db, db> x, pair<db, db> y){
//   return sqrt(hypot(y.fi - x.fi, y.se - x.se));
// }

db area(pair<db, db> x, pair<db, db> y, pair<db, db> z){
  return (1.0/2.0)*abs((x.fi - z.fi)*(y.se - x.se) - (x.fi - y.fi)*(z.se - x.se));
}

pair<db, db> getPoint(pair<pair<db, db>, db> x, pair<pair<db, db>, db> y){
  pair<db, db> res;
  res.fi = (x.se*y.fi.se - x.fi.se*y.se)/(x.fi.fi*y.fi.se - x.fi.se*y.fi.fi);
  res.se = (x.fi.fi*y.se - x.se*y.fi.fi)/(x.fi.fi*y.fi.se - x.fi.se*y.fi.fi);
  // res.fi = (x.se - y.se * (x.fi.se / y.fi.se))/(x.fi.fi - y.fi.fi * (x.fi.se / y.fi.se));
  // res.se = (x.se - y.se * (x.fi.fi / y.fi.fi))/(x.fi.se - y.fi.se * (x.fi.fi / y.fi.fi));
  return res;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll n;
  cin >> n;
  pair<pair<db, db>, db> fir;
  pair<pair<db, db>, db> sec;
  pair<pair<db, db>, db> cur;

  cin >> fir.fi.fi >> fir.fi.se >> fir.se;
  cin >> sec.fi.fi >> sec.fi.se >> sec.se;

  pair<db, db> p1 = getPoint(fir, sec);
  pair<db, db> p2, p3;
  db ans = 0;
  for(ll i = 0; i < n-2; i++){
    cin >> cur.fi.fi >> cur.fi.se >> cur.se;
    p2 = getPoint(fir, cur);
    p3 = getPoint(sec, cur);
    ans += area(p1, p2, p3);
  }
  // cout << distant(p1, p2) << el;
  // cout << heron(distant(p1, p2), distant(p2, p3), distant(p1, p3)) << el;
  prs(6);
  cout << (ans)/(n-2.0);
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
