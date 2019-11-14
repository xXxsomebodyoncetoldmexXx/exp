#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI  =3.141592653589793238463;

using namespace std;

#ifdef LOCAL_PROJECT
#define CURTIME() cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#else
#define CURTIME() ;
#endif

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define prs(n) cout << fixed << setprecision(n)
#define DEBUG(val) cerr << "#####\nRunning on Line " << __LINE__ << " in Function " << 	__FUNCTION__ << el << val << "#####";
#define el "\n"
#define sp " "

// RNG - for sum fun
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Combination calculate
ll nCr(ll n, ll r){
	// The fomular:
	// n! / (r! * (n-r)!)
	// Complexity: O(r)
	ll tmp = n-r;
	for(ll i = n-1; i > tmp; i--)
		n *= i;

	for(ll i = r-1; i > 1; i--)
		r *= i;
	return n/r;
}

vector<ll> isP(6e6);
vector<ll> dp(6e6);
const ll inf = 6e6 - 7;

/*******************************
* NO IDEA WHAT THE FUCK IS THIS*
*******************************/

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
#endif

  // INIT SIEVE
  for(ll i = 2; i < inf; i++)
  	isP[i] = i;

  // SIEVE
  for(ll i = 2; i*i < inf; i++)
  	if(isP[i] == i)
  		for(ll j = i*i; j < inf; j+=i)
  			isP[j] = min(i, isP[j]);

  // DP TO GENERATE F(x)
  for(ll i = 2; i < inf; i++){
  	dp[i] = 1e17;
  	for(ll j = i; j != 1; j /= isP[j])
  		dp[i] = min(dp[i], dp[i/isP[j]] + i*(isP[j]-1)/2);
  }
  for(ll i = 0 ; i < 10; i++)
  	cout << i << sp << dp[i] << el;
	ll t, l, r;
	cin >> t >> l >> r;
	ll exp = 1;
	ll ans = 0;
	ll MOD = 1e9+7;
	for(ll i = l; i <= r; i++){
		dp[i] %= MOD;
		ans = (ans%MOD + (exp*dp[i])%MOD )%MOD;
		exp = (exp*t)%MOD;
	}
	cout << ans;

	CURTIME();
	return 0;
}
