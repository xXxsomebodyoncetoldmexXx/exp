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
#define el "\n"


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef LOCAL_PROJECT
	freopen("in", "r", stdin);
	#endif

	ll n, q;
	cin >> n >> q;
	vector<ll> war(n);
	vector<ll> preCom(n);
	vector<ll> arr(n);
	for(auto &i : war)
		cin >> i;
	for(auto &i : arr)
		cin >> i;
	preCom[0] = war[0];
	for(ll i = 1; i < n; i++)
		preCom[i] = preCom[i-1] + war[i];
	ll totalHeal = preCom[n-1];
	ll curArr = 0;
	for(ll time = 0; time < q; time++){
		curArr += arr[time];
		if(curArr >= totalHeal){
			cout << n << el;
			curArr = 0;
		}
		else{
			auto idx = lb(preCom.begin(), preCom.end(), curArr);
			if(*idx - curArr == 0){
				idx++;
			}
			cout << n - (idx - preCom.begin()) << el;
		}
	}
	return 0;
}
