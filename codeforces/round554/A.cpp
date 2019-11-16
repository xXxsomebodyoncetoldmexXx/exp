#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI  =3.141592653589793238463;

using namespace std;

#ifdef LOCAL_PROJECT
#define CURTIME() 				cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name) 			freopen(name, "r", stdin)
#define OUFILE(name) 			freopen(name, "w", stdin)
#define DEBUG 						cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " << 	__FUNCTION__ << "\n##########\n"
#define DUMP(name, value) cerr << "[" << (name) << "]: " << (value) << el
#else
#define CURTIME() 				;
#define INFILE(name) 			;
#define OUFILE(name) 			;
#define DEBUG 						;
#define DUMP(name, value) ;
#endif

#define FASTIO 						ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mp 								make_pair
#define mt 								make_tuple
#define pb 								push_back
#define fi 								first
#define se 								second
#define lb 								lower_bound
#define ub 								upper_bound
#define prs(n) 						cout << fixed << setprecision(n)
#define el 								"\n"
#define sp 								" "

// RNG - for sum fun
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Combination calculate
// Note to self: n >= r
// From N pieces pick R pieces
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
	FASTIO;
	INFILE("in");
	//OUFILE("out");

	ll n, m;
	cin >> n >> m;
	ll c0, c1;
	ll tmp;

	c0 = c1 = 0;
	for(ll i = 0; i < n; i++){
		cin >> tmp;
		if(tmp%2)
			c1++;
		else
			c0++;
	}

	ll k0, k1;
	k0 = k1 = 0;
	for(ll i = 0; i < m; i++){
		cin >> tmp;
		if(tmp%2)
			k1++;
		else
			k0++;
	}
	DUMP("c0", c0);
	DUMP("c1", c1);
	DUMP("k0", k0);
	DUMP("k1", k1);
	cout << min(c0, k1) + min(c1, k0);
	CURTIME();
	return 0;
}
