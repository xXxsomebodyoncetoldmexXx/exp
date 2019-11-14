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



int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	ll n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<ll> ans(n+1);
	for(ll i = 0; i <= m-n; i++){
		vector<ll> change(0);
		for(ll j = 0; j < n; j++)
			if(s[j] != t[j+i])
				change.pb(j+1);
		if(change.size() <= ans.size())
			ans = change;
	}
	cout << ans.size() << el;
	for(auto i : ans)
		cout << i << sp;
	CURTIME();
	return 0;
}
