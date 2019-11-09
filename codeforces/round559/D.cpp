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

#define create_variable ll n, k;
#define get_input cin >> n >> k;
#define magic_num ll patr = (n-k)/2;
#define a_loop for(ll i = 0; i < n; i++)
#define print_ans cout << (((i+1)%(patr+1)) == 0);


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

  // CHECK THERE CASE AND YOU WILL SEE THE PATTERN
  // n == k
  // n == k-2 (cause you know, k%2 == n%2)
  // n == k-4
  // ...
  // Todo: improve it so don't need the (k%2) == (n%2)



	create_variable
	get_input
	magic_num
	a_loop
	print_ans

	return 0;
}
