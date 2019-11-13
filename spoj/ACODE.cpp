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

map<string, ll> memo;

ll re(char *s, ll siz){
	if(siz < 1 || s[0] == '0')
		return 0;
	if(memo[s])
		return memo[s];
	memo[s] = re(s+1, siz-1);
	if(s[0] == '2' || s[0] == '1')
		memo[s] += re(s+2, siz-2);
	return memo[s];
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif
  memo["1"] = 1;
  memo["2"] = 1;
  memo["3"] = 1;
  memo["4"] = 1;
  memo["5"] = 1;
  memo["6"] = 1;
  memo["7"] = 1;
  memo["8"] = 1;
  memo["9"] = 1;
  memo["10"] = 1;
  memo["20"] = 1;

  memo["11"] = 2;
  memo["12"] = 2;
  memo["13"] = 2;
  memo["14"] = 2;
  memo["15"] = 2;
  memo["16"] = 2;
  memo["17"] = 2;
  memo["18"] = 2;
  memo["19"] = 2;
  memo["21"] = 2;
  memo["22"] = 2;
  memo["23"] = 2;
  memo["24"] = 2;
  memo["25"] = 2;
  memo["26"] = 2;

	char s[10000];
	cin >> s;
	while(s[0] != '0'){
		cout << re(s, strlen(s)) << el;
		cin >> s;
	}
	return 0;
}
