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

  string s;
  stack<vector<ll>> st;
  cin >> s;
  for(ll i = 1; i < s.size(); i++){
    if(s[i] != s[i-1]){
      vector<ll> tmp;
      tmp.push_back(1);
      tmp.push_back(-(i*2 + 1));
      st.push(tmp);
    }
  }
  if(st.empty()){
    cout << 0 << el;
    if(s[0] == 'H')
      cout << 1;
    else
      cout << -1;
    exit(0);
  }
  vector<ll> cur = st.top();
  st.pop();
  while(!st.empty()){
    vector<ll> first = cur;
    vector<ll> second = st.top();
    vector<ll> newer(first.size() + 1, 0);
    cur = newer;
    for(ll i = 0; i < first.size(); i++){
      for(ll j = 0; j < second.size(); j++){
        cur[i+j] += first[i] * second[j];
        // DUMP(second[i]);
      }
    }
    st.pop();
  }
  cout << cur.size()-1 << "\n";
  ll sw = 1;
  if(s[s.size()-1] == 'A')
    sw*= -1;
  for(ll i = 0; i < cur.size(); i++)
    cout << cur[i] * sw<< " ";
  CURTIME();
  return 0;
}
