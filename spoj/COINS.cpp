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

map<ll, ll> memo;

ll re(ll coin){
	if(memo[coin])
		return memo[coin];
	memo[coin] = coin;
	ll check = (coin/2) + (coin/3) + (coin/4);
	if(check > coin)
		memo[coin] = re(coin/2) + re(coin/3) + re(coin/4);
	return memo[coin];
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

	string s;
	while(getline(cin, s)){
		ll n = stoll(s, 0, 0);
		cout << re(n) << el;
	}
	return 0;
}
