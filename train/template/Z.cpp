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

vector<ll> Z(string s){
  ll L, R, n;
  n = s.size();
  vector<ll> z(n, 0);
  L = R = 0;
  for(ll i = 1; i < n; i++){
    if(i > R){
      L = R = i;
      while(R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
    else{
      ll k = i - L;
      if(z[k] < R-i+1) z[i] = z[k];
      else{
        L = i;
        while(R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      }
    }
  }
  return z;
}


vector<ll> newZ(string s){
  ll L, R, n, k;
  n = s.size();
  vector<ll> z(n, 0);
  L = R = 0;
  for(ll i = 1; i < n; i++){
    if(i > R){
      L = R = i;
      while(R < n && s[R-L] == s[R]) R++;
      z[i] = R - L; R--;
    }
    else{
      k = i - L;
      if(z[k] < R - i + 1) z[i] = z[k];
      else{
        L = i;
        while(R < n && s[R-L] == s[R]) R++;
        z[i] = R - L; R--;
      }
    }
  }
  return z;
}

// https://codeforces.com/contest/126/problem/B

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");

  string s;
  cin >> s;
  // cout << s << el;
  vector<ll> z = Z(s);
  for(auto i : z)
    cout << i << sp;
  cout << el;
  z = newZ(s);
  for(auto i : z)
    cout << i << sp;
  CURTIME();
  exit(0);
  ll mx = -1;
  ll n = s.size();
  for(ll i = 1; i < n; i++){
    // DUMP(z[i]);
    if(z[i] == n-i && mx >= z[i]){
      for(ll j = i; j < i+z[i]; j++)
        cout << s[j];
      exit(0);
    }
    mx = max(mx, z[i]);
  }
  cout << "Just a legend";
  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
