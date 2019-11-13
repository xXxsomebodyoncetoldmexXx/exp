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

bool placeAble(ll val, ll cow, vector<ll> v){
	ll valid = 1;
	ll cur = 0;
	for(ull i = 1; i < v.size(); i++){
		if(v[i] - v[cur] >= val){
			cur = i;
			valid++;
		}
	}
	if(valid < cow)
		return false;
	return true;
}

ll binS(ll lelf, ll right, ll cow, vector<ll> v){
	ll mid, ans;
	ans = 1;
	while(lelf <= right){
		mid = lelf + (right - lelf)/2;
		if(placeAble(mid, cow, v)){
			ans = mid;
			lelf = mid+1;
		}
		else
			right = mid-1;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

	ll T, n, cow;
	cin >> T;
	while(T--){
		cin >> n >> cow;
		vector<ll> v(n);
		for(auto &i : v)
			cin >> i;
		sort(v.begin(), v.end());
		cout << binS(1, v[n-1] - v[0], cow, v) << el;
	}
	return 0;
}
