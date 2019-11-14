#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI  =3.141592653589793238463;

using namespace std;

#define mp make_pair
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

db cal(db num){
	return pow(num, 2)*PI;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

	ll n;
	db val;
	cin >> n;
	prs(10);
	vector<db> v(n);
	for(auto &i : v)
		cin >> i;
	sort(v.rbegin(), v.rend());
	bool toggle = true;
	db ans = 0;
	for(auto i : v){
		if(toggle)
			ans += cal(i);
		else
			ans -= cal(i);
		toggle = !toggle;
	}
	cout << ans;
	return 0;
}
