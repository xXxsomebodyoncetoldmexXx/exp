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

ll val, nxt;

void query(ll idx){
	cout << "? " << idx << endl;
	cin >> val >> nxt;
	if(val == -1 && nxt == -1)
		exit(0);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

	ll n, st, x;
	cin >> n >> st >> x;
	if(n <= 2000){
		vector<ll> ar(n);
		for(ll i = 0; i < n; i++){
			query(i+1);
			ar[i] = val;
		}
		sort(ar.begin(), ar.end());
		auto iter = lb(ar.begin(), ar.end(), x);
		if(iter == ar.end())
			cout << "! -1" << endl;
		else
			cout << "! " << ar[iter - ar.begin()] << endl;
	}
	else{
		vector<pair<ll, ll>> ar;
		vector<bool> isV(n+1, false);
		ll pos = st;
		query(st);
		isV[st] = true;
		ll startV = val;
		ar.pb(mp(val, nxt));
		ll idx;
		for(ll i = 0; i < 1499; i++){
			do{
				idx = (rng()%n) + 1;
			}while(isV[idx]);
			isV[idx] = false;
			query(idx);
			ar.pb(mp(val, nxt));
		}

		sort(ar.begin(), ar.end());

		val = startV;
		nxt = pos;
		for(auto p : ar){
			if(p.fi == x){
				cout << "! " << x << endl;
				exit(0);
			}
			if(p.fi > x)
				break;
			val = p.fi;
			nxt = p.se;
		}
		for(ll i = 0; i < 500; i++){
			if(val >= x){
				cout << "! " << val << endl;
				exit(0);
			}
			if(nxt == -1)
				cout << "! -1" << endl;
			query(nxt);
		}
	}
	return 0;
}
