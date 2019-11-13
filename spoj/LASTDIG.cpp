#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;

using namespace std;

#define el "\n"

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

	ll n, num ,base;
	cin >> n;
	while(n--){
		cin >> num >> base;
		ll ans = 1;
		if(base){
			base = (base-1)%4;
			for(ll i = 0; i <= base; i++)
				ans *= num;
		}
		cout << ans%10 << el;
	}
	return 0;
}
