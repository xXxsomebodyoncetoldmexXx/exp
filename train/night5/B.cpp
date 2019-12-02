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
vector<ll> fac(ll n){
  vector<ll> ans;
  ans.pb(1);
  for(ll i = 2; i*i <= n; i++){
    if(n%i == 0){
      ans.pb(i);
      if(n/i != i)
        ans.pb(n/i);
    }
  }
  if(n!= 1)
    ans.pb(n);
  return ans;
}

// BinSearch
bool is_perfect(ll num){
  // ll st, ed, mid, check;
  // st = 1;
  // ed = (num/2) + 1;
  // while(st <= ed){
  //   mid = (st+ed)/2;
  //   check = mid*mid;
  //   if(check == num)
  //     return true;
  //   else if(check < num)
  //     st = mid+1;
  //   else
  //     ed = mid-1;
  // }
  ll check = round(sqrt(num));
  return num == (check*check);
}

bool check(ll num){
  // DUMP(num);
  if(is_perfect(num))
    return false;
  for(ll i = 2; i*i <= num; i++){
    // DUMP(i);
    if(num%i == 0){
      if(is_perfect(i) || is_perfect(num/i))
        return false;
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  ll n;
  cin >> n;
  vector<ll> factor = fac(n);
  // Prime
  // for(auto i : factor)
  //   cout << i << sp;
  // cout << el;
  sort(ALL(factor));
  if(factor.size() == 2)
    cout << factor[1];
  else{
    for(ll i = factor.size()-1; i>0; i--){
      if(check(factor[i])){
        cout << factor[i];
        CURTIME();
        exit(0);
      }
    }
    cout << 1;
  }
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
