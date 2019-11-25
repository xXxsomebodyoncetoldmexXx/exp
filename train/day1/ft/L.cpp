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
#define DUMP(name, value) cerr << "[" << (name) << "]: " << (value) << el
#else
#define CURTIME()         ;
#define INFILE(name)      ;
#define OUFILE(name)      ;
#define DEBUG             ;
#define DUMP(name, value) ;
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

string ori, mod;
ll total, correct;
ll suppose, cur;

void re(ll idx){
  DUMP("cur", cur);
  if(idx >= ori.size()){
    if(cur == suppose)
      correct++;
    total++;
    // DUMP("correct", correct);
    // DUMP("total", total);
    return;
  }
  if(mod[idx] == '+'){
    cur++;
    re(++idx);
    cur--;
  }
  else if(mod[idx] == '-'){
    cur--;
    re(++idx);
    cur++;
  }
  else{
    cur--;
    re(++idx);
    cur += 2;
    re(idx);
    cur--;
  }
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  //OUFILE("out");

  cin >> ori >> mod;
  for(auto c : ori){
    if(c == '+')
      suppose++;
    else
      suppose--;
  }
  prs(10);
  DUMP("suppose", suppose);
  re(0);
  cout << (correct*1.0)/total;
  CURTIME();
  return 0;
}
