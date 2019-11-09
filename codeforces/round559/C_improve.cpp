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

	ll b, g;
	cin >> b >> g;
	vector<ll> boy(b);
	vector<ll> girl(g);
	ll max1, max2, sum;
	bool isSat = false;
	max1 = max2 = sum = 0;
	for(auto &i : boy){
		cin >> i;
		sum += i;
		if(i >= max1){
			max2 = max1;
			max1 = i;
		}
		else if(i > max2)
			max2 = i;
	}
	ll ans = sum * g;
	ll mn = 10e10;
	for(auto &i : girl){
		cin >> i;
		mn = min(mn, i);
		ans += i;
		if(i == max1)
			isSat = true;
	}
	if(isSat)
		ans -= max1 * g;
	else
		ans -= ((max1 * (g-1)) + max2);
	if(mn < max1)
		ans = -1;
	cout << ans;
	return 0;
}
