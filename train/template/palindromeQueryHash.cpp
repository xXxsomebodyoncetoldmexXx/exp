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
#define RALL(v)             (v).rbegin(), (v).rend()
#define LXCMP(s, t)         lexicographical_compare(ALL(s), ALL(t))  // s > t
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

inline ll mul(ll a, ll b, ll MOD = (1LL<<62)){
  return ((((a)%MOD)*((b)%MOD))%MOD);
}

inline ll add(ll a, ll b, ll MOD = (1LL<<62)){
  return ((((a)%MOD)+((b)%MOD))%MOD);
}

/*  CODE BEGIN FROM HERE  */

vector<ull> prefix;
vector<ull> surfix;
vector<ull> hsh;

ll const MOD = 1000*1000*1000 + 7;
ll const P = 41;

#define mul(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define add(a, b) ((((a)%MOD)+((b)%MOD))%MOD)

void comHash(){
  hsh.pb(1LL);
  for(ll i = 1; i <= 1000*1000; i++)
    hsh.pb(mul(hsh.back(), P));
}

void compPre(string s){
  prefix.pb(0LL);
  for(ll i = 1; i <= s.size(); i++){
    prefix.pb(add(prefix.back(), mul(s[i-1], hsh[i-1])));
    // DUMP(prefix.back());
  }
}

void compSur(string s){
  surfix.pb(0LL);
  for(ll i = 1; i <= s.size(); i++){
    surfix.pb(add(surfix.back(), mul(s[i-1], hsh[i-1])));
    // DUMP(surfix.back());
  }
}

ull powMOD(ull base, ull exp){
  if(!exp)
    return 1;
  if(exp == 1)
    return base;
  ull tmp = powMOD(base, exp/2);
  tmp = mul(tmp, tmp);
  if(exp%2!=0)
    tmp = mul(tmp, base);
  return tmp;
}

ll Pow(ll base, ll exp, ll MOD = (1LL<<62)){
  ll ans = 1;
  while(exp){
    if(exp & 1)
      ans = (ans*base)%MOD;
    exp >>= 1;
    base = (base*base)%MOD;
  } 
  return ans;
}

void preProcess(string s){
  comHash();
  compPre(s);
  reverse(all(s));
  compSur(s);
}

bool checkPalindrome(ll L, ll R, ll n){
  ull preHash = prefix[R] - prefix[L-1];
  ull surHash = surfix[n - L + 1] - surfix[n - R];
  ull missing = Pow(P, abs((n - R + 1) - L), MOD);
  if(min(preHash, surHash) * missing == max(preHash, surHash))
    return true;
  return false;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  string s;
  cin >> s;
  preProcess(s);
  ll q;
  ll a, b;
  cin >> q;
  while(q--){
    cin >> a >> b;
    if(checkPalindrome(a, b, s.size()))
      cout << "YES" << el;
    else
      cout << "NO" << el;
  }
  
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
