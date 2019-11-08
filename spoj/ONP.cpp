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

	ll n;
	string s;
	stack<char> st;
	cin >> n;
	while(n--){
		cin >> s;
		string ans;
		for(auto c : s){
			if(c == '(')
				continue;
			else if(c == ')'){
				ans.pb(st.top());
				st.pop();
				continue;
			}
			else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
				st.push(c);
				continue;
			}
			ans.pb(c);
		}
		cout << ans << el;
	}
	return 0;
}
