#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI  =3.141592653589793238463;

using namespace std;

#ifdef LOCAL_PROJECT
#define CURTIME() cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name) freopen(name, "r", stdin)
#define OUFILE(name) freopen(name, "w", stdin)
#else
#define CURTIME() ;
#define INFILE(name) ;
#define OUFILE(name) ;
#endif

#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL)
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

vector<pair< pair<ll, bool>, pair<ll, ll> >> queries;
vector<ll> minDay(3e6, 1e17);

int main(int argc, char const *argv[]) {
	FASTIO;
	INFILE("in");
	// OUFILE("out");

	ll vou, day;
	cin >> vou >> day;
	for(ll i = 0; i < vou; i++){
		ll lelf, right, cost;
		cin >> lelf >> right >> cost;
		queries.pb(mp( mp(lelf, 0), mp(right - lelf + 1, cost) ));
		queries.pb(mp( mp(right, 1), mp(right - lelf + 1, cost) ));
	}
	sort(queries.begin(), queries.end());

	ll ans = 1e17;

	for(auto q : queries){
		if(q.se.fi <= day){
			if(!q.fi.se){
				ans = min(ans, q.se.se + minDay[day - q.se.fi]);
			}
			else
				minDay[q.se.fi] = min(minDay[q.se.fi], q.se.se);
		}
	}
	if(ans > 2e9)
		cout << -1;
	else
		cout << ans;
	CURTIME();
	return 0;
}
