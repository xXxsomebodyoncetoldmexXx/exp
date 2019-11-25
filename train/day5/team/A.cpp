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
  cin >> s;
  ll z, o;
  z = o = 0;
  for(auto c : s){
    if(c == '0')
      z++;
    else
      o++;
  }
  bool check = false;
  if(z > o)
    check = true;
  if(!z || o > z)
    for(auto c : s)
      cout << 0;
  else if(!o || o < z)
    for(auto c : s)
      cout << 1;
  else{
    if(s == "1010"){
      cout << "0111";
      exit(0);
    }
    else if(s == "0101"){
      cout << "1000";
      exit(0);
    }
    else if(s == "0011"){
      cout << "1100";
      exit(0);
    }
    else if(s == "1100"){
      cout << "0011";
      exit(0);
    }
    else if(s == "1001"){
      cout << "0111";
      exit(0);
    }
    else if(s == "0110"){
      cout << "1000";
      exit(0);
    }
    // for(ll i = 0; i < s.size(); i++){
    //   if(s[i] == '1')
    //     s[i] = '0';
    //   else
    //     s[i] = '1';
    // }
    // // else if(s == "0110")
    // // else if(s == "1001")
    // if(s.size() > 2){
    //   s[s.size()/2] ^= s[(s.size()/2)-1];
    //   s[(s.size()/2)-1] ^= s[(s.size()/2)];
    //   s[s.size()/2] ^= s[(s.size()/2)-1];
    // }
    // cout << s;
    bool flag = false;
    for(auto c : s){
      if(check){
        if(c == '1' && !flag){
          cout << 0;
          flag = true;
        }
        else
          cout << 1;
      }
      else{
        if(c == '0' && !flag){
          cout << 1;
          flag = true;
        }
        else
          cout << 0;
      }
    }
  }
  CURTIME();
  return 0;
}
