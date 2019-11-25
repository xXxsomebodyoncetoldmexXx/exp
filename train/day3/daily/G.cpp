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



int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  //OUFILE("out");

  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for(auto &i : v)
    cin >> i;
  sort(v.begin(), v.end());
  vector<ll> query;
  query.pb(v[0]);
  ll cur = v[0];
  for(ll i = 1; i < n; i++){
    if(cur < v[i]){
      query.pb(v[i] - cur);
      cur += (v[i] - cur);
    }
  }
  // for(auto i : query)
  //   DUMP(i);
  query.pb(-1);
  ll idx = 0;
  while(k--){
    if(query[idx] == -1)
      cout << 0 << el;
    else{
      cout << query[idx] << el;
      // query[idx]--;
      // if(query[idx] == 0)
      idx++;
    }
  }
  
  CURTIME();
  return 0;
}
