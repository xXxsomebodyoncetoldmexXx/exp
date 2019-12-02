#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI = 3.141592653589793238462643383279502884;
const double esp = 1e-7;

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

ll ppl, dis, Vwalk, Vbus, seat, group;

bool isGood(db time){
  db Tpass = 0;
  for(ll i = 1; i <= group; i++){
    // We have CurPos = Vwalk*Tpass - those who don't take the bus last time
    // disLelf = dis - CurPos
    // We assume bus run a distant of: Vbus*x
    // Tlelft = time - Tpass - x
    // walk the rest: Vwalk*Tlelft
    // BUT we have: disLelf = Vbus*x + Vwalk*Tlelft
    // SO WE HAVE AN EQUATION: Vbus*x + Vwalk*(time - Tpass - x) = dis - CurPos
    // Vbus*x + Vwalk*time - Vwalk*Tpass - Vwalk*x = dis - Vwalk*Tpass
    // x*(Vbus - Vwalk) = dis - Vwalk*Tpass - Vwalk*time + Vwalk*Tpass
    // x*(Vbus - Vwalk) = dis - Vwalk*time
    // x = (dis - Vwalk*time)/(Vbus - Vwalk) -> Opimal time for bus to carry ppl to the end
    db x = ((dis - Vwalk*time) * 1.0)/(Vbus - Vwalk);
    Tpass += x;

    // WE NEED TO PUT THE BUS BACK TO GET THE NEXT GROUP
    if(i < group)
      // Now the bus as position: Vbus*x
      // The group is moving more: Vwalk*x
      // Suppose after y second both bus and group will meet
      // The group moving more with: Vwalk*y
      // The bus is moving more: -Vbus*y
      // Final equation: Vwalk*x + Vwalk*y = Vbus*x - Vbus*y
      // y(Vwalk + Vbus) = x(Vbus - Vwalk)
      // y = (x*Vbus - x*Vwalk)/(Vwalk + Vbus) -> Time two group gonna meet each other
      Tpass += ((x*Vbus - x*Vwalk) * 1.0)/(Vwalk+Vbus);
    if(Tpass > time)
      return false;
  }
  return true;
}

bool shortIsGood(db time){
  db x = ((dis - Vwalk*time) * 1.0)/(Vbus - Vwalk);
  // Cause this x is alway const with every iterator, we can shorten it to this
  db Tpass = x*group;

  db y = ((x*Vbus - x*Vwalk) * 1.0)/(Vwalk+Vbus);
  // This y we only add 'group-1' time so we can make it into
  Tpass += y*(group-1);

  if(Tpass > time)
    return false;
  return true;
}

db binS(db st, db ed){
  db mid;
  while((ed - st) > esp){
    mid = (st+ed)/2.0;
    if(shortIsGood(mid))
      ed = mid-esp;
    else
      st = mid+esp;
  }
  return st;
}

int main(int argc, char const *argv[]) {
  FASTIO;
  INFILE("in");
  // OUFILE("out");
  
  cin >> ppl >> dis >> Vwalk >> Vbus >> seat;
  group = (ppl+seat-1)/seat;
  prs(9);
  cout << binS(0, (dis+Vwalk-1)/Vwalk);

  CURTIME();
  return 0;
}

/******************************
 *         WHITE_FOX          *
 ******************************/
