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
  #define DEBUG()           cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
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
vector<vector<ll>> edge;
vector<vector<ll>> people;
ll par[500000][21];
vector<ll> total[500000][21];
ll heigh[500000];

inline vector<ll> operator +(vector<ll> &u, vector<ll> &v){
  vector<ll> ans;
  ull i, j;
  i = j = 0;
  while(i < u.size() && j < v.size()){
    if(u[i] <= v[j])
      ans.pb(u[i++]);
    else
      ans.pb(v[j++]);
  }
  while(i < u.size())
    ans.pb(u[i++]);
  while(j < v.size())
    ans.pb(v[j++]);
  return ans;
}

inline void dfs(ll cur, ll prev = 0){
  par[cur][0] = prev;
  // DUMP(par[cur][0]);
  if(prev){
    total[cur][0] = people[cur] + people[prev];
    heigh[cur] = heigh[prev]+1;
  }
  for(ll i = 1; i < 20; i++){
    // DUMP(par[par[cur][i-1]]);
    if(par[cur][i-1]){
      // DUMP(par[cur][i-1]);
      // DUMP(par[par[cur][i-1]][i-1]);
      par[cur][i] = par[par[cur][i-1]][i-1];
      total[cur][i] = total[cur][i-1] + total[par[cur][i-1]][i-1];
    }
  }
  for(auto eg : edge[cur])
    if(eg != prev)
      dfs(eg, cur);
}

inline vector<ll> lca(ll u, ll v){
  // vector<ll> ans;
  vector<ll> ans = people[u] + people[v];
  if(heigh[u] < heigh[v])
    swap(u, v);
  for(ll i = 19; i >= 0; i--){
    if(par[u][i] && heigh[par[u][i]] >= heigh[v]){
      ans = ans + total[u][i];
      u = par[u][i];
    }
  }
  DUMP(ans.size());
  if(u == v)
    return ans;
  for(ll i = 19; i >= 0; i--){
    if(par[u][i] != par[v][i]){
      ans = ans + total[u][i];
      ans = ans + total[v][i];
      v = par[v][i];
      u = par[u][i];
    }
  }
  ans = ans + people[par[u][0]];
  return ans;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll n, m, q;
  cin >> n >> m >> q;

  edge = vector<vector<ll>>(n+1);
  people = vector<vector<ll>>(n+1);
  ll a, b;
  for(ll i = 0; i < n-1; i++){
    cin >> a >> b;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  for(ll i = 0; i < m; i++){
    cin >> a;
    if(people[a].size() < 11)
      people[a].pb(i+1);
  }
  dfs(1);
  ll x;
  vector<ll> ans;
  while(q--){
    cin >> a >> b >> x;
    ans = lca(a, b);
    set<ll> out(ALL(ans));
    cout << out.size() << sp;
    for(auto i : out)
      cout << i << sp;
    cout << el;
  }
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
