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

/***********************IDEA***************************
* We use dfs to count number of time we use that edge *
* Magic is at min(isUse[cur], 2*k - isUse[cur])       *
* Basicly it guarrenty that atleast that amount       *
* of Node is going to go through that current Node    *
* so we just need to add it to our answer.            *
*******************************************************/

vector<ll> edge[300000];
vector<ll> listUni;
map<ll, ll> isUse;
ll ans;
ll n, k;

void dfs(ll cur, ll prev){
  for(auto i : edge[cur]){
    if(i != prev){
      dfs(i, cur);
      isUse[cur] += isUse[i];
    }
  }
  ans += min(isUse[cur], 2*k - isUse[cur]);
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  cin >> n >> k;
  for(ll i = 0; i < k*2; i++){
    ll tmp;
    cin >> tmp;
    listUni.pb(tmp);
    isUse[tmp]++;
  }
  for(ll i = 1; i < n; i++){
    ll a, b;
    cin >> a >> b;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  dfs(1, -1);
  cout << ans;
  
  CURTIME();
  return 0;
}

/*
BFS METHOD BY kcm1700

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> cnt(n);
  vector<vector<int>> graph(n);
  for (int i = 0; i < 2 * k; i ++) {
    int pos;
    scanf("%d", &pos);
    pos--;
    cnt[pos]++;
  }
  for (int i = 0; i < n - 1;i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<int> order;
  vector<int> par(n);
  queue<int> q;
  vector<bool> visit(n);
  order.push_back(0);
  q.push(0);
  par[0] = -1;
  visit[0] = true;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto next : graph[cur]) {
      if (visit[next])
        continue;
      order.push_back(next);
      par[next] = cur;
      visit[next] = true;
      q.push(next);
    }
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int cur = order[i];
    int parent = par[cur];
    if (parent != -1) {
      ans += min(2*k - cnt[cur], cnt[cur]);
      cnt[parent] += cnt[cur];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
*/

/******************************
 *         WHITE_FOX          *
 ******************************/
