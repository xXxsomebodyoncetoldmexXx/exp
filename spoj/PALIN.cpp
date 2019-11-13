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

deque<char> ans;
ll idx;

bool all9(string s){
	for(auto c : s)
		if(c != '9')
			return false;
	return true;
}

void plusOne(string s){
	idx = s.size()/2;
	if(s.size()%2 == 0)
		idx--;
	s[idx] = s[idx]-'0' + 1;
	bool carry = s[idx] / 10;
	s[idx] = (s[idx] % 10) + '0';
	ans.pb(s[idx]);
	if(idx != s.size()/2)
		ans.pb(s[idx]);
	for(ll i = idx-1; i >= 0; i--){
		if(carry){
			s[i] = s[i] - '0' + 1;
			carry = s[i] / 10;
			s[i] = (s[i] % 10) + '0';
		}
		ans.pb(s[i]);
		ans.push_front(s[i]);
	}
	if(carry){
		ans.push_front('1');
		ans.pb('1');
	}
}

void dup(string s){
	ll i = (s.size()-1)/2;
	if(s.size()%2 != 0){
		ans.pb(s[i]);
		i--;
	}
	while(i >= 0){
		ans.pb(s[i]);
		ans.push_front(s[i]);
		i--;
	}
}

bool check(string s){
	ll si = s.size()-1;
	ll i = si/2;
	while(i >= 0){
		if(s[i] > s[si-i])
			return false;
		else if(s[i] < s[si - i])
			break;
		i--;
	}
	return true;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL_PROJECT
  freopen("in", "r", stdin);
//freopen("out", "w", stdout);
#endif

	ll T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		bool needAdd = check(s);
		if(all9(s)){
			for(ll i = 0; i < s.size()-1; i++)
				ans.pb('0');	
			ans.pb('1');
			ans.push_front('1');
		}
		else if(needAdd){
			plusOne(s);
		}
		else{
			dup(s);
		}
		while(!ans.empty()){
			cout << ans.front();
			ans.pop_front();
		}
		cout << el;
	}
	return 0;
}
