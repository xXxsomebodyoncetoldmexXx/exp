#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI = 3.141592653589793238463;

using namespace std;
  
#ifdef LOCAL_PROJECT
#define CURTIME()         cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdin)
#define DEBUG             cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
#define DUMP(name, value) cerr << "[" << (name) << "]: " << (value) << el
#else
#define CURTIME()         ;
#define INFILE(name)      ;
#define OUFILE(name)      ;
#define DEBUG             ;
#define DUMP(name, value) ;
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

ll sTol(string x, ll l, ll r){
  ll total = 0;
  for(ll i = l; i < r; i++)
    total = total*10 + (x[i]-'0');
  return total;
}

ll fromOne(string s){
  ll ans = 0;
  ll limit = sTol(s, 0, s.size());
  ull thing = 999;
  if(limit > 9)
    ans += 9;
  if(limit > 99)
    ans += 9;
  while(limit > thing){
    ans += 10;
    thing= thing*10 + 9;
  }
  if(s.size() > 2){
    ans += (9*pow(10, s.size()-2)) - sTol(s, 1, s.size()-1);
    if(s[0] >= s[s.size()-1])
      ans++;
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  //OUFILE("out");

  string l, r;
  cin >> l >> r;
  ll Lval = fromOne(l);
  ll Rval = fromOne(r);
  DUMP("lval", Lval);
  DUMP("rval", Rval);
  cout << Rval - Lval;
  
  CURTIME();
  return 0;
}
