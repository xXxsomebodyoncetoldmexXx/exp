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
	ll base, ans;
	ans = n;

	// First attemp
	// base = 2;
	// ll tmp;
	// while((n/base)){
	// 	tmp = (n/base)-(base-1);
	// 	if(tmp > 0)
	// 		ans += tmp;
	// 	else
	// 		break;
	// 	base++;
	// }

	for(ll i = 2; i*i <= n; i++)
		ans += (n/i) - (i-1);

	cout << ans;
	return 0;
}
