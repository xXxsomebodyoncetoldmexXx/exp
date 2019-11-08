#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define prs(n) cout << setprecision(n)
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

map<ll, ll> meet;
map<pair<ll, ll>, ll> same;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef LOCAL_PROJECT
	  freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	#endif

	ll n, a, b;
	cin >> n >> a >> b;
	vector<pair<ll, pair<ll,ll>>> pos(n);
	ll ans = 0;

	for(auto &i : pos){
		cin >> i.fi;
		cin >> i.se.fi;
		cin >> i.se.se;
		ans += meet[a*i.se.fi - i.se.se] - same[mp(i.se.fi, i.se.se)];
		same[mp(i.se.fi, i.se.se)]++;
		meet[a*i.se.fi - i.se.se]++;
	}
	cout << ans*2;
	// for(auto i : pos)
	// 	cout << i.fi << sp << i.se.fi << sp << i.se.se << el;
	return 0;
}
