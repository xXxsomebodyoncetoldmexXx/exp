#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define prs(n) cout << fixed << setprecision(n)
#define el "\n"
#define sp " "

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

	ll n;
	cin >> n;
	vector<ll> v(n);
	for(auto &i : v)
		cin >> i;
	// ll ans = 10e10;
	ll ans = min(v[0], v[n-1]) / (n-1);
	for(ll i = 1; i < n-1; i++){
		ll pos = max(i, n-i-1);
		ans = min(ans, v[i] / pos);
	}
	cout << ans;
	return 0;
}
