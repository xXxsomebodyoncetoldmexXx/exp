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

vector<vector<string>> all;
vector<string> tmp;

void gen(string s, ll idx, string cur){
  if(idx == s.size()){
    if(cur != "")
      tmp.pb(cur);
  }
  else{
    gen(s, idx+1, cur);
    cur.pb(s[idx]);
    gen(s, idx+1, cur);
    cur.pop_back();
  }
}

bool lagr(string s, string t){
  return lexicographical_compare(t.begin(), t.end(), s.begin(), s.end());
}


bool smlr(string s, string t){
  return lexicographical_compare(s.begin(), s.end(), t.begin(), t.end());
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  //OUFILE("out");

  ll n;
  cin >> n;
  vector<string> v(n);
  for(auto &i : v)
    cin >> i;
  if(n == 1){
    cout << v[0].size() << el;
    exit(0);
  }
  reverse(v.begin(), v.end());
  for(auto s : v){
    gen(s, 0, "");
    all.pb(tmp);
    tmp.clear();
  }
  // for(auto i : all){
  //   cout << i.size() << el;      
  //   for(auto j : i)
  //     cout << j << el;
  // }
  sort(all[0].begin(), all[0].end(), lagr);
  vector<pair<string, ll>> cur, nxt;
  ll mx = 0LL;
  for(auto i : all[0]){
    mx = max(mx, (ll)(i.size()));
    cur.pb(mp(i, mx));
  }

  // string s = "YORO";
  // string t = "Z";
  // cout << lexicographical_compare(s.begin(), s.end(), t.begin(), t.end()) << el;

  ll ans = 0;
  // for(auto i : cur)
  //   cout << i.fi << sp << i.se << el;
  // exit(0);
  for(ll i = 1; i < all.size(); i++){
    mx = 0LL;
   sort(all[i].begin(), all[i].end(), lagr);
   nxt.clear();
   for(auto j : all[i]){
    mx = max(mx, (ll)(j.size()));
    nxt.pb(mp(j, mx));
   }
   ll idx = 0;
   for(ll j = 0; j < nxt.size(); j++){
      if(idx >= cur.size()){
        nxt[j].se = nxt[j-1].se;
        continue;
      }
      // cout << i.fi << el;
      DUMP(nxt[j].fi);
      DUMP(nxt[j].se);
      for(ll k = idx; k < cur.size(); k++, idx++){
        DUMP(cur[k].fi);
        if(lagr(cur[k].fi, nxt[j].fi))
          continue;
        break;
      }
      // if(idx == 0){
      //   cout << -1;
      //   exit(0);
      //   nxt[j].se = 0;
      //   continue;
      // }
      if(idx < cur.size()){
        if(idx == 0)
          nxt[j].se = 0;
        else
          nxt[j].se += cur[idx-1].se;
        continue
      }
      // if(idx >= cur.size()){
      //   nxt[j].se = nxt[j-1].se;
      //   continue;
      // }
      nxt[j].se += cur[idx-1].se;
      DUMP(nxt[j].se);
      // cout << "---" << el;
      DUMP("---");
   }
   cur = nxt;
   // cout << nxt[nxt.size()-1].se << el;
  }
  cout << cur[cur.size()-1].se;
  // cout << *ub(all[0].begin(), all[0].end(), "bc", smlr);
  CURTIME();
  return 0;
}
