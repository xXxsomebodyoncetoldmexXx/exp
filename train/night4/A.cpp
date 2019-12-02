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

map<pair<ull, ull>, string> memo;

/*  CODE BEGIN FROM HERE  */
string binS(ull a, ull b){
  ull val = a*b;
  ull st, ed;
  ull mid, check;

  mid = check = val/3;
  st = 1;
  ed = 1000005;
  // Find cube root
  /********** 950s **********/
  while(st <= ed){
    mid = (st+ed)/2;
    check = mid*mid*mid;
    if(check == val)
      break;
    else if(check > val)
      ed = mid-1;
    else
      st = mid+1;
  }

  /********** 998s ********/
  // mid = round(cbrt(val));
  // check = mid*mid*mid;
  // DUMP(cbrt(val));
  /************************/

  if(check == val && a%mid==0 && b%mid==0)
    return "Yes";
  return "No";
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll n;
  cin >> n;
  memo[mp(1,1)] = "Yes";
  while(n--){
    ull a, b;
    cin >> a >> b;
    // PURE MATH
    // https://codeforces.com/blog/entry/53567?#comment-376161
    ull check = a+b;
    if((check%3 == 0) && (a - (check/3)) >= 0 && (b - (check/3)) >= 0)
      puts("Yes");
    else
      puts("No");
    // if(memo[mp(a, b)].empty()){
    //   // memo[mp(a, b)] = memo[mp(b, a)] = binS(a, b);

    // }
    
    // cout << memo[mp(a,b)] << el;
  }
  
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
