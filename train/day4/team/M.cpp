#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define po pop
#define pu push
#define ety empty
#define tp top
#define ft front
#define bk back
#define ll long long
 
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for(ll i = 0; i < n; i++)
		cin >> v[i];
	ll ans = 1;
	for(ll i = 0; i < n-1; i++){
		ll tmp = 1;
		for(ll j = i+1; j < n; j++){
			if(v[j]-v[j-1] <= x)
				tmp++;
			else
				break;
		}
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}
