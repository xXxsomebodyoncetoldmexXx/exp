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
// lpsa
vector<ll> init(string s){
  ll n = s.size();
  ll len = 0;
  vector<ll> lps(n, 0);
  ll idx = 1;
  while(idx < n){
    // If current character is part of string prefix
    if(s[idx] == s[len]){
      len++;
      lps[idx] = len;
      idx++;
    }
    // If it not equal anymore
    else{ //s[idx] != s[len]
      if(len != 0)
        len = lps[len-1];
      else
        lps[idx++] = 0;
    }
  }
  return lps;
}

vector<ll> init2(string s){
  ll n = s.size();
  vector<ll> lsp(n, 0);
  ll j;
  for(ll i = 1; i < n; i++){
    j = lsp[i-1];
    while(j > 0 && s[i] != s[j])
      j = lsp[j-1];
    if(s[i] == s[j])
      j++;
    lsp[i] = j;
  }
  return lsp;
}

vector<ll> kmp(string s, string pat, vector<ll> lsp = vector<ll>(0)){
  if(lsp.size() == 0)
    lsp = init(pat);
  vector<ll> ans;
  ll n = s.size();
  ll t = pat.size();
  ll i, j;
  i = j = 0;
  cout << lsp.size() << el;
  for(auto i : lsp)
    cout << i << sp;
  cout << el;
  while(i < n){
    if(s[i] == pat[j])  // Have a match
      i++, j++;
    if(j == t){         // Full match
      ans.pb(i-j);
      j = lsp[j-1];
    }
    else if(i < n && pat[j] != s[i]){
      if(j != 0)  // Go back to the closest prefix
        j = lsp[j-1];
      else        // Checking the next character
        i++;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  string s, p;
  cin >> s >> p;
  vector<ll> check = init2(p);
  cout << check.size() << el;
  for(auto i : check)
    cout << i << sp;
  exit(0);
  vector<ll> ret = kmp(s, p, init(p));
  cout << ret.size() << el;
  for(auto i : ret)
    cout << i << sp;
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
