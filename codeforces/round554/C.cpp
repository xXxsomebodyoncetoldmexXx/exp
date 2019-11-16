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

ll Gcd(ll a, ll b){
	while((a%=b) && (b%=a));
	return a+b;
}

ll lcm(ll a, ll b){
	return (a*b)/Gcd(a,b);
}

vector<ll> fac(ll num){
	vector<ll> ret;
	for(ll i = 1; i*i <= num; i++)
		if(num%i == 0){
			ret.pb(i);
			if(num/i != i)
				ret.pb(num/i);
		}
	return ret;
}

int main(int argc, char const *argv[]) {
	FASTIO;
	INFILE("in");
	//OUFILE("out");

	ll a, b;
	cin >> a >> b;
	ll dif = abs(a-b);
	vector<ll> f = fac(dif);
	sort(f.rbegin(), f.rend());
	ll ans = 0;
	ll val = (1LL << 62);
	ll check;
	for(auto i : f){
		if(a%i != b%i)
			continue;
		if(a%i == 0){
			check = lcm(a, b);
			if(check < val){
				val = check;
				ans = 0;
			}
		}
		else{
			ll step = i - (a%i);
			check = lcm(a+step, b+step);
			if(check < val){
				val = check;
				ans = step;
			}
		}
	}
	cout << ans;
	CURTIME();
	return 0;
}
