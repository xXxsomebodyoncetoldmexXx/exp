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

string re;

void query(ll x, ll y){
  cout << "? " << x << sp << y << endl;
  cin >> re;
  if(re.compare("mistake") == 0 || re.compare("e") == 0)
    exit(0);
}

int main(int argc, char const *argv[]) {
  FASTIO;
  // INFILE("in");
  // OUFILE("out");

  string cmd;
  cin >> cmd;
  while(!cmd.compare("start")){
    query(0, 1);
    ll offset = 0;
    while(re.compare("y") == 0){
      query((1<<offset), (1<<(offset+1)));
      offset++;
    }
    if(offset)
      offset--;
    // DUMP(offset);
    ll left = 1<<offset;
    ll right = 1<<(offset+1);
    ll low = left;
    ll mid;
    while(left < right){
      mid = (left + (right - left)/2);
      query(low, mid);
      if(re.compare("x") == 0)
        right = mid-1;
      else
        left = mid+1;
    }
    cout << "! " << mid << endl;
    cin >> cmd;
  }  
  CURTIME();
  return 0;
}
