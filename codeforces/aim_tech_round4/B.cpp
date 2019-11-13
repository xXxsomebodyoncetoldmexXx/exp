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



int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

  ll r, c;
  cin >> r >> c;
  vector<vector<ll>> matrix(r, vector<ll> (c));
  for(ll i = 0; i < r; i++)
  	for(ll j = 0; j < c; j++)
  		cin >> matrix[i][j];
  ll ans;
  ull zero, one;
  ans = 0;
  ans -= r*c;
  for(ll i = 0; i < r; i++){
  	zero = one = 0;
  	for(ll j = 0; j < c; j++){
  		if(matrix[i][j])
  			one++;
  		else
  			zero++;
  	}
  	ans += pow(2, one) - 1;
  	ans += pow(2, zero) - 1;
  }
  for(ll i = 0; i < c; i++){
  	zero = one = 0;
  	for(ll j = 0; j < r; j++){
  		if(matrix[j][i])
  			one++;
  		else
  			zero++;
  	}
  	ans += pow(2, one) - 1;
  	ans += pow(2, zero) - 1;
  }
  cout << ans;
	return 0;
}
