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
	while(n != -1){
		vector<ll> v(n);
		ll total = 0;
		for(auto &i : v){
			cin >> i;
			total += i;
		}
		db avg = (total*1.0)/n;
		total /= n;
		if(abs(avg - total) < 10e-4){
			ll ans = 0;
			for(auto i : v){
				if (i > total)
				ans += i - total;
			}
			cout << ans << el;
		}
		else
			cout << -1 << el;
		cin >> n;
	}
	return 0;
}
