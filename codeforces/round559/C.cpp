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

	ll ng, nb, ans, idx;
	cin >> nb >> ng;
	vector<ll> boy(nb);
	vector<ll> girl(ng);
	bool isSat = false;
	ans = 0;
	for(auto &i : boy){
		cin >> i;
		ans += i;
	}
	sort(boy.rbegin(), boy.rend());
	for(auto &i : girl){
		cin >> i;
		if(i == boy[0])
			isSat = true;
	}
	sort(girl.rbegin(), girl.rend());
	if(girl[ng-1] < boy[0])
		cout << -1;
	else{
		ans *= girl.size();
		idx = 0;
		while(idx < ng-1){
			if(girl[idx] >= boy[0]){
				if(girl[idx] == boy[0])
					isSat = true;
				ans += girl[idx] - boy[0];
				idx++;
				continue;
			}
			break;
		}
		ll next = boy[0];
		if(!isSat)
			next = boy[1];
		while(idx < ng){
			ans += girl[idx] - next;
			idx++;
		}
		cout << ans;
	}
	return 0;
}
